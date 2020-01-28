#ifndef __CMD_STATE_UPDATE_H__
#define __CMD_STATE_UPDATE_H__

#include <string>
#include <vector>
#include "State.h"

namespace cmd {
class StateUpdate {
public:
    explicit StateUpdate();
    bool hasUpdate(const State& current, State& newState) const;
    bool setUpdate(const State& newState);
    bool setCommand(const char* command, State& newState);
    const State& getCurrent() const { return current; }
    const State& getPrevious() const { return previous; }
private:
    std::vector<std::string> split(std::string str, std::string separator) const;
    State current;
    State previous;

}; // StateUpdate

} // cmd

#endif // __CMD_STATE_UPDATE_H__
