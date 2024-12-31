#include <iostream>

#include "textadventure/action.h"
#include "textadventure/all_scenes.h"
#include "textadventure/scene.h"
#include "textadventure/state.h"

namespace game {

namespace {

class DescribeAction : public game::Action {
 public:
  std::string Name() const override { return "Describe"; };
  void Execute(game::State* state) override {
    std::cout << state->CurrentScene()->Description() << std::endl;
  }
};

class EnterMineAction : public game::Action {
 public:
  std::string Name() const override { return "Step into The Mine"; };
  void Execute(game::State* state) override {
    state->ToScene(game::scenes::MineEntry(state));
  }
};

class GoToCastleAction : public game::Action {
 public:
  std::string Name() const override { return "Go to The Castle"; };
  void Execute(game::State* state) override {
    state->ToScene(game::scenes::Castle(state));
  }
};

class ShowGemAction : public game::Action {
 public:
  std::string Name() const override { return "Show Gem"; };
  void Execute(game::State* state) override {
    if (state->CurrentScene() == game::scenes::Castle(state)) {
      if (!state->PlayerHasGem()) {
        std::cout << "You do not have a gem.\n" << std::endl;
        state->GameOver();
      }
    }
  }
};

class TakeTorchAction : public game::Action {
 public:
  std::string Name() const override { return "Take Torch"; };
  void Execute(game::State* state) override {
    state->SetPlayerHasTorch(true);
    std::cout << "You take the torch.\n" << std::endl;
  }
};

class DiveDeeperAction : public game::Action {
 public:
  std::string Name() const override { return "Dive Deeper"; };
  void Execute(game::State* state) override {
    state->ToScene(game::scenes::MineGate(state));
  }
};

#define STATIC_GAME_ACTION(prefix) \
  Action* prefix() {               \
    static prefix##Action a;       \
    return &a;                     \
  }

}  // namespace
namespace actions {
STATIC_GAME_ACTION(Describe)
STATIC_GAME_ACTION(EnterMine)
STATIC_GAME_ACTION(GoToCastle)
STATIC_GAME_ACTION(ShowGem)
STATIC_GAME_ACTION(TakeTorch)
STATIC_GAME_ACTION(DiveDeeper)

}  // namespace actions
}  // namespace game
