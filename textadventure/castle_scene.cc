#include "textadventure/castle_scene.h"

#include "textadventure/action.h"
#include "textadventure/all_actions.h"
#include "textadventure/scene.h"

namespace game {
namespace scenes {

std::string CastleScene::Description() const {
  return R"(You stand in front of The Castle.

The Guard intercepts you before you approach.

The Guard says, "You! Gem Hunter! Stop there and present your best gem.")";
}

std::vector<game::Action*> CastleScene::Actions() const {
  return {
      game::actions::Describe(),
      game::actions::EnterMine(),
  };
}

}  // namespace scenes
}  // namespace game