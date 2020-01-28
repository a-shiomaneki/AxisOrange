#include "StateUpdate.h"

namespace cmd {

StateUpdate::StateUpdate() : current(StateAwake), previous(StateAwake) {

}

bool StateUpdate::hasUpdate(const State& current, State& newState) const {
    if (this->current == current) {
        return false;
    }
    newState = this->current;
    return true;
}

bool StateUpdate::setUpdate(const State& newState) {
    if (current == newState) {
        return false;
    }
    previous = current;
    current = newState;
    return true;
}

bool StateUpdate::setCommand(const char* command, State& newState) {
    std::string str(command);
    if (str.size < 1) return false;

    std::vector<std::string> splited = split(str, " ");
    std::string type = splited[0];

    if (splited.size < 2) {
        if (type == CmdIdle) {
            previous = current;
            newState = current = StateIdle;
            return true;
        }
        if (type == CmdNotify) {
            previous = current;
            newState = current = StateNotify_tagq;
            return true;
        }
        if (type == CmdGyroOffsetInstall) {
            previous = current;
            newState = current = StateGyroOffsetInstall_start;
            return true;
        }
        return false;
    }

    std::string val = splited[1];
    if (type == CmdNotify) {
        previous = current;
        if (val == "t") {
            newState = current = StateNotify_t;
        } else if (val == "a") {
            newState = current = StateNotify_a;
        } else if (val == "g") {
            newState = current = StateNotify_g;
        } else if (val == "q") {
            newState = current = StateNotify_q;
        } else if (val == "ta") {
            newState = current = StateNotify_ta;
        } else if (val == "tg") {
            newState = current = StateNotify_tg;
        } else if (val == "tq") {
            newState = current = StateNotify_tq;
        } else {
            newState = current = StateNotify_tagq;
        }
        return true;
    }

    if (type == CmdGyroOffsetInstall) {
        previous = current;
        if (val == "0") {
            newState = current = StateGyroOffsetInstall_reset;
        } else {
            newState = current = StateGyroOffsetInstall_start;
        }
        return true;
    }

    return false;
}

std::vector<std::string> StateUpdate::split(std::string str, std::string separator) const {
    if (separator == "") return {str};
    std::vector<std::string> result;
    std::string tstr = str + separator;
    long l = tstr.length(), sl = separator.length();
    std::string::size_type pos = 0, prev = 0;
    
    for (;pos < l && (pos = tstr.find(separator, pos)) != std::string::npos; prev = (pos += sl)) {
        result.emplace_back(tstr, prev, pos - prev);
    }
    return result;
}

} // cmd
