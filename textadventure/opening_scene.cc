#include "textadventure/opening_scene.h"

#include "textadventure/action.h"
#include "textadventure/common_actions.h"
#include "textadventure/scene.h"

namespace game {
namespace scenes {
OpeningScene::OpeningScene(game::State* state) : _state(state) {}

std::string OpeningScene::Name() const { return "The Opening"; }

std::string OpeningScene::Description() const {
  return R"(You are a Gem Hunter!
Princess Krystalia seeks the best Gem in all of the land.

She offers her hand in marriage to the one who rises to the challenge.

Behind you, The Castle sparkles against blue sky, standing tall and majestically adorned.
In front of you, the dark darkness of The Mine...)";
}

std::vector<game::Action*> OpeningScene::Actions() const {
  return {
      game::actions::GoToCastle(),
      game::actions::EnterMine(),
  };
}

}  // namespace scenes
}  // namespace game