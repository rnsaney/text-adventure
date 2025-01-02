#include "textadventure/mine_entry_scene.h"

#include <memory>
#include <vector>

#include "textadventure/action.h"
#include "textadventure/common_actions.h"
#include "textadventure/scene.h"

namespace game {
namespace scenes {
MineEntryScene::MineEntryScene(game::State* state) : _state(state) {}

std::string MineEntryScene::Name() const { return "Mine Entry"; }

std::string MineEntryScene::Description() const {
  std::string desc = "The sunlight barely seeps through cracks.";
  if (_state->PlayerHasTorch()) {
    desc.append("\nYou hold a torch to light the way.\n");
  } else {
    desc.append(
        "\nYou are drawn to a faint flicker.\n"
        "You come to a small room where a torch hangs on the wall, lighting "
        "the room.\n");
  }
  desc.append("A winding stairwell lies ahead.");
  return desc;
}

const std::vector<ActionStruct> MineEntryScene::Actions() const {
  std::vector<ActionStruct> result;
  if (!_state->PlayerHasTorch()) {
    result.push_back(game::actions::TakeTorchAction());
  }
  result.push_back(game::actions::DiveDeeperAction());
  return result;
}

}  // namespace scenes
}  // namespace game