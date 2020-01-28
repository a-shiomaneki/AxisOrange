#ifndef __CMD_STATE_H__
#define __CMD_STATE_H__

namespace cmd {
    enum State {
        DevStateAwake = 0,
        DevStateIdle = 1,
        DevStateNotify = 2,
        DevStateGyroOffsetInstall = 3
    };
}

#endif // __CMD_STATE_H__
