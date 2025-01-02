#include "textadventure/castle_scene.h"

#include <iostream>
#include <memory>

#include "textadventure/action.h"
#include "textadventure/common_actions.h"
#include "textadventure/scene.h"

namespace game {
namespace scenes {

CastleScene::CastleScene(game::State* state) : _state(state) {}

std::string CastleScene::Name() const { return "The Castle"; }

std::string CastleScene::Description() const {
  return R"(You stand in front of The Castle. It looms vast. A maiden is visible in a high window.
You take one step forward.

The Guard intercepts you before you approach.

The Guard says, "You! Gem Hunter! Stop there and present your best gem.")";
}

const std::vector<ActionStruct> CastleScene::Actions() const {
  return {
      game::actions::ShowGemAction(),
      game::actions::GoToOpeningFieldAction(),
  };
}

void CastleScene::Reaction() { GuardSpeaks(); }

void CastleScene::GuardSpeaks() const {
  if (_state->IsGameOver()) {
    auto response = R"(
The Guard: "No Gem!? Wastin' the pricesses' time!? Agh I'll kill you right now!"

The Guard stabs you, and you die.
)";
    std::cout << response << std::endl;
  }
}

}  // namespace scenes
}  // namespace game