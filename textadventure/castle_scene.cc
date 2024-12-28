#include "textadventure/castle_scene.h"

#include <iostream>

#include "textadventure/action.h"
#include "textadventure/all_actions.h"
#include "textadventure/scene.h"

namespace game {
namespace scenes {

CastleScene::CastleScene(game::State* state) : _state(state) {}

std::string CastleScene::Description() const {
  return R"(You stand in front of The Castle.

The Guard intercepts you before you approach.

The Guard says, "You! Gem Hunter! Stop there and present your best gem.")";
}

std::vector<game::Action*> CastleScene::Actions() const {
  return {
      game::actions::ShowGem(),
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