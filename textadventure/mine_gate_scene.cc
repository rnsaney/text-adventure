#include "textadventure/mine_gate_scene.h"

#include <iostream>

#include "textadventure/action.h"
#include "textadventure/all_scenes.h"
#include "textadventure/common_actions.h"
#include "textadventure/scene.h"

namespace game {
namespace scenes {
namespace {
class TurnBackAction : public game::Action {
 public:
  std::string Name() const override { return "Turn Back"; };
  void Execute(game::State* state) override {
    state->ToScene(game::scenes::MineEntry(state));
  }
};

Action* TurnBack() {
  static TurnBackAction a;
  return &a;
}

class FiddleWithPadlockAction : public game::Action {
 public:
  std::string Name() const override { return "Fiddle with Padlock"; };
  void Execute(game::State* state) override {
    std::cout << "The padlock digits are set to 4610."
                 "\nThe lock won't budge."
              << std::endl;
  }
};

Action* FiddleWithPadlock() {
  static FiddleWithPadlockAction a;
  return &a;
}
}  // namespace

MineGateScene::MineGateScene(game::State* state) : _state(state) {}

std::string MineGateScene::Name() const { return "Mine Gate"; }

std::string MineGateScene::Description() const {
  std::string desc;
  if (!_state->PlayerHasTorch()) {
    desc.append(
        "The room is pitch black. There is no option but to turn back.");
  } else {
    desc.append(
        "There is a gate ahead. Almost like a prison cell.\n"
        "On closer inspection, a 4-digit padlock fastens the door.\n"
        "There is a tunnel and slight draft coming up from behind The Gate.\n"
        "\n"
        R"(You realize, "I --must-- go deeper, the gems is I need is beyond this gate!")"
        "\n"
        "To the side is a small bed with a notebook.\n");
  }
  return desc;
}

std::vector<game::Action*> MineGateScene::Actions() const {
  std::vector<game::Action*> result;
  if (!_state->PlayerHasTorch()) {
    result.push_back(TurnBack());
  } else {
    result.push_back(FiddleWithPadlock());
  }
  return result;
}

}  // namespace scenes
}  // namespace game