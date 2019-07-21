
//
// Copyright by Magnus Olsen 2019 under GPL 2.0 or close source licens by Magnus Olsen writen premitions.
//
//#define _WIN32_WINNT 0x501

#include <stdio.h>
#include <stdlib.h>

#include "../../dyad/src/dyad.h"

#define txtServerVersion "vGPU server Version 1.0 alpha\0"
#define intServerPort 8000

void wellcomeMsg();
int vgpu_cmd(dyad_Event *e);




static void onData(dyad_Event *e) {

  int err;
  printf("Server onData: %s\n", e->data);
  err = vgpu_cmd(e);
  if (err != 0) {
    // ToDo close this steam instead do hard exit
   // exit(-1);
  }

}

static void onAccept(dyad_Event *e) {

  printf("server onAccept: %s\n", e->msg);

  dyad_addListener(e->remote, DYAD_EVENT_DATA, onData, NULL);

  // write back hello msg
  dyad_writef(e->remote, "%s", txtServerVersion);
}

static void onError(dyad_Event *e) {
  printf("server error: %s\n", e->msg);
}


int main(void) {

  wellcomeMsg();

  dyad_Stream *s;
  dyad_init();

  s = dyad_newStream();
  dyad_addListener(s, DYAD_EVENT_ERROR,  onError,  NULL);
  dyad_addListener(s, DYAD_EVENT_ACCEPT, onAccept, NULL);
  dyad_listen(s, intServerPort);

  while (1) {

    while (dyad_getStreamCount() > 0) {
        dyad_update();
    }

  }


  return 0;
}

void wellcomeMsg() {
    printf("Wellcome to %s\nIt need better name\n",txtServerVersion);
    printf("it is a exprement server see if opengl commands can be transfer\n");
    printf("over a network.\nFrom Windows XP/VISTA/7/8/8.1/10 32bits opengl client to Debian 64bits Opengl\n\n");
    printf("The server can be compile to 32bit instead for 64bits,\nIt can even be compile and run on windows NT XP or higher\n");
    printf("The server licens is under GPL 2.0 or close source licens by my premitions.\n");
    printf("®Copyright Magnus Olsen 2019 magnus@greatlor.com\n");
}
