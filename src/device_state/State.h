#ifndef __DEVICE_STATE_STATE_H__
#define __DEVICE_STATE_STATE_H__

namespace device_state {
    enum State {
        DevStateAwake = 0,
        DevStateIdle = 1,
        DevStateNotify = 2,
        DevStateGyroOffsetInstall = 3
    };
}

#endif // __DEVICE_STATE_STATE_H__
