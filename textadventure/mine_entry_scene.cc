#include "textadventure/mine_entry_scene.h"

#include <memory>
#include <vector>

#include "textadventure/action.h"
#include "textadventure/common_actions.h"
#include "textadventure/scene.h"

namespace game {
namespace scenes {
MineEntryScene::MineEntryScene(game::State* state) : _state(state) {
  _take_torch_action = std::make_shared<game::actions::TakeTorchAction>();
  _dive_deeper_action = std::make_shared<game::actions::DiveDeeperAction>();
}

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

std::vector<std::shared_ptr<Action>> MineEntryScene::Actions() const {
  std::vector<std::shared_ptr<Action>> result;
  if (!_state->PlayerHasTorch()) {
    result.push_back(_take_torch_action);
  }
  result.push_back(_dive_deeper_action);
  return result;
}

}  // namespace scenes
}  // namespace game