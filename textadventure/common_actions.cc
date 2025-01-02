#include "textadventure/common_actions.h"

#include <iostream>

#include "textadventure/action.h"
#include "textadventure/all_scenes.h"
#include "textadventure/scene.h"
#include "textadventure/state.h"

namespace game {
namespace actions {

ActionStruct DescribeAction() {
  return {.name = "Describe", .action_fn = [](std::shared_ptr<State> state) {
            std::cout << state->CurrentScene()->Description() << std::endl;
          }};
}

ActionStruct GoToOpeningFieldAction() {
  return {.name = "Go to Opening Field",
          .action_fn = [](std::shared_ptr<State> state) {
            state->ToScene(game::scenes::Opening(state.get()));
          }};
}

ActionStruct EnterMineAction() {
  return {.name = "Step into The Mine",
          .action_fn = [](std::shared_ptr<State> state) {
            state->ToScene(game::scenes::MineEntry(state.get()));
          }};
}

ActionStruct GoToCastleAction() {
  return {.name = "Go to The Castle",
          .action_fn = [](std::shared_ptr<State> state) {
            state->ToScene(game::scenes::Castle(state.get()));
          }};
}

// TODO: Refactor to CastleScene implementation.
ActionStruct ShowGemAction() {
  return {.name = "Show Gem", .action_fn = [](std::shared_ptr<State> state) {
            if (state->CurrentScene() == game::scenes::Castle(state.get())) {
              if (!state->PlayerHasGem()) {
                std::cout << "You do not have a gem.\n" << std::endl;
                state->GameOver();
              }
            }
          }};
}

// TODO: Refactor to Mine Entry implementation.
ActionStruct TakeTorchAction() {
  return {.name = "Take Torch", .action_fn = [](std::shared_ptr<State> state) {
            state->SetPlayerHasTorch(true);
            std::cout << "You take the torch!" << std::endl;
          }};
}

// TODO: Refactor to Mine Entry implementation.
ActionStruct DiveDeeperAction() {
  return {.name = "Dive Deeper", .action_fn = [](std::shared_ptr<State> state) {
            state->ToScene(game::scenes::MineGate(state.get()));
          }};
}

}  // namespace actions
}  // namespace game
