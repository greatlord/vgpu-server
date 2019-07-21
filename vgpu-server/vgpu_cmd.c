
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>



#include "../../dyad/src/dyad.h"

#include "vgpu-common.h"

#define MAX_VGPU_CLIENTS    256

// global value only use here
int vgpu_client_id = -1;
VPGU_CLIENT_TRACK vgpu_client_track[MAX_VGPU_CLIENTS];


int vpgu_check_client_version( PVGPU_TRANS_HEAD head, int size ) {

    if ( size < sizeof(VGPU_TRANS_HEAD) ) {
        return -1;
    }

    if ( strcmp( head->txtVersion, txtClientVersion) != 0) {
        return -1;
    }

    return 1;
}

int createNewClientId( PVGPU_TRANS_HEAD head, dyad_Event *e ) {

    int newClient = false;

     // client ask for new clientid
    if ( head->clientId == -1 ) {

        if ( vgpu_client_id >= MAX_VGPU_CLIENTS ) {
            return -2;
        }
        vgpu_client_id++;

        head->clientId = vgpu_client_id;

        vgpu_client_track[vgpu_client_id].clientVersion = head->clientId;

        // setup server info
        sprintf(head->txtVersion,"%s",txtServerVersion);
        head->serverVersion = 1;

        dyad_write(e->stream, head, sizeof(VGPU_TRANS_HEAD));

        newClient = true;
    }
    return newClient;
}

int vgpu_check_if_client_is_vaild(PVGPU_TRANS_HEAD head, dyad_Event *e  ) {

	int ret;

	// check if it a vgpu client
    ret = vpgu_check_client_version(head, e->size);
    if (!ret) {
        // no gpu client found
        return -1;
    }

    // client ask for new clientid
    ret = createNewClientId(head, e);
    if ( ret == -2 ) {
        // out of of ClientIds
        return -2;
    }
    if (ret) {
        return 2;
    }
    return 1;
}


int vgpu_cmd(dyad_Event *e) {

    int ret;
    PVGPU_TRANS_HEAD head;

     // transform begin of data to our header
    head = (PVGPU_TRANS_HEAD) e->data;


    ret = vgpu_check_if_client_is_vaild( head, e);
    if (!ret) {
        // no gpu client found or other errors
        // -1 = no gpu client found
        // -2 = out of of ClientIds
        return -1;
    }

    printf(" server client id : %d \n", head->clientId);

    if ( ret == 2) {
        // it was a new client. waiting on commands now
        return 0;
    }

    // we got data to *e
    // send back same data
   // dyad_write(e->stream, e->data, e->size);

    return 0;
}
