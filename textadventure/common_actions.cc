#include "textadventure/common_actions.h"

#include <iostream>

#include "textadventure/action.h"
#include "textadventure/all_scenes.h"
#include "textadventure/scene.h"
#include "textadventure/state.h"

namespace game {
namespace actions {

std::string DescribeAction::Name() const { return "Describe"; }
void DescribeAction::Execute(game::State* state) {
  std::cout << state->CurrentScene()->Description() << std::endl;
}

std::string GoToOpeningFieldAction::Name() const {
  return "Go to Opening Field";
}
void GoToOpeningFieldAction::Execute(game::State* state) {
  state->ToScene(game::scenes::Opening(state));
}

std::string EnterMineAction::Name() const { return "Step into The Mine"; }
void EnterMineAction::Execute(game::State* state) {
  state->ToScene(game::scenes::MineEntry(state));
}

std::string GoToCastleAction::Name() const { return "Go to The Castle"; };
void GoToCastleAction::Execute(game::State* state) {
  state->ToScene(game::scenes::Castle(state));
}

std::string ShowGemAction::Name() const { return "Show Gem"; }
void ShowGemAction::Execute(game::State* state) {
  if (state->CurrentScene() == game::scenes::Castle(state)) {
    if (!state->PlayerHasGem()) {
      std::cout << "You do not have a gem.\n" << std::endl;
      state->GameOver();
    }
  }
}

std::string TakeTorchAction::Name() const { return "Take Torch"; };
void TakeTorchAction::Execute(game::State* state) {
  state->SetPlayerHasTorch(true);
  std::cout << "You take the torch!" << std::endl;
}

std::string DiveDeeperAction::Name() const { return "Dive Deeper"; };
void DiveDeeperAction::Execute(game::State* state) {
  state->ToScene(game::scenes::MineGate(state));
}

}  // namespace actions
}  // namespace game
