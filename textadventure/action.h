#ifndef TEXTADVENTURE_ACTION_H
#define TEXTADVENTURE_ACTION_H

#include <string>

#include "textadventure/state.h"

namespace game {

class State;

class Action {
 public:
  virtual ~Action() = default;
  virtual std::string Name() const = 0;
  virtual void Execute(State* state) = 0;
};

}  // namespace game

#endif  // TEXTADVENTURE_ACTION_H