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

}  // namespace actions
}  // namespace game
