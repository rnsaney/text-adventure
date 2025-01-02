#include "textadventure/opening_scene.h"

#include <memory>

#include "textadventure/action.h"
#include "textadventure/common_actions.h"
#include "textadventure/scene.h"

namespace game {
namespace scenes {
std::string OpeningScene::Name() const { return "Opening Field"; }

std::string OpeningScene::Description() const {
  return R"(You are a Gem Hunter!
Princess Krystalia seeks the best Gem in all of the land.

She offers her hand in marriage to the one who rises to the challenge.

You stand in a large field of green grass.
Behind you, The Castle sparkles against blue sky, standing tall and majestically adorned.
In front of you, the dark darkness of The Mine...)";
}

const std::vector<ActionStruct> OpeningScene::Actions() const {
  return {
      game::actions::GoToCastleAction(),
      game::actions::EnterMineAction(),
  };
}

}  // namespace scenes
}  // namespace game