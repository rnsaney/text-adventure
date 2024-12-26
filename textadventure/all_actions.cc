#include <iostream>

#include "textadventure/action.h"
#include "textadventure/scene.h"
#include "textadventure/state.h"

namespace game {

namespace {

class DescribeAction : public game::Action {
 public:
  std::string Name() const override { return "Describe"; };
  void Execute(game::State* state) override {
    std::cout << state->current_scene->Description() << std::endl;
  }
};

class EnterMineAction : public game::Action {
 public:
  std::string Name() const override { return "Step into The Mine"; };
  void Execute(game::State* state) override { state->ToScene("The Mine"); }
};

class GoToCastleAction : public game::Action {
 public:
  std::string Name() const override { return "Go to The Castle"; };
  void Execute(game::State* state) override { state->ToScene("The Castle"); }
};

}  // namespace

namespace actions {
Action* Describe() {
  static DescribeAction a;
  return &a;
}

Action* EnterMine() {
  static EnterMineAction a;
  return &a;
}

Action* GoToCastle() {
  static GoToCastleAction a;
  return &a;
}
}  // namespace actions
}  // namespace game