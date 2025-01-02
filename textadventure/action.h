#ifndef TEXTADVENTURE_ACTION_H
#define TEXTADVENTURE_ACTION_H

#include <functional>
#include <memory>
#include <string>

#include "textadventure/state.h"

namespace game {

class State;

struct ActionStruct {
  const std::string name;
  const std::function<void(std::shared_ptr<State>)> action_fn;
};

}  // namespace game

#endif  // TEXTADVENTURE_ACTION_H
