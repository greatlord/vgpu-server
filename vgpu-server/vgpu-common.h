
// Server and Client common parts

#define txtServerVersion "vGPU server Version 1.0 alpha\0"
#define txtClientVersion "vGPU client Version 1.0 alpha\0"

typedef  struct _STRUCT_VGPU_TRANS_HEAD_ {
    char txtVersion[255];
    uint32_t serverId;
    uint32_t serverVersion;
    uint32_t clientId;
    uint32_t clientVersion;

    uint32_t cmd;
} VGPU_TRANS_HEAD, *PVGPU_TRANS_HEAD;


// server parts only
typedef struct {

    uint32_t clientVersion;

} VPGU_CLIENT_TRACK, *PVPGU_CLIENT_TRACK;

int vpgu_check_client_version( PVGPU_TRANS_HEAD head, int size );
int createNewClientId( PVGPU_TRANS_HEAD head, dyad_Event *e );

// commands
#define VGPU_CMD_HELLO  0

