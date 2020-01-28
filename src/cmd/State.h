#ifndef __CMD_STATE_H__
#define __CMD_STATE_H__

namespace cmd {

const char* CmdIdle = "idle";
const char* CmdNotify = "notify";
const char* CmdGyroOffsetInstall = "gyro_offset_install";

enum State {
    StateAwake = 0,
    StateIdle = 1,
    StateNotify_t = 10,
    StateNotify_a = 11,
    StateNotify_g = 12,
    StateNotify_q = 13,
    StateNotify_ta = 14,
    StateNotify_tg = 15,
    StateNotify_tq = 16,
    StateNotify_tagq = 17,
    StateGyroOffsetInstall_start = 20,
    StateGyroOffsetInstall_reset = 21
};

}

#endif // __CMD_STATE_H__
