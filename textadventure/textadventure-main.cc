#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "textadventure/action.h"
#include "textadventure/scene.h"
#include "textadventure/state.h"

namespace {

class DescribeAction : public game::Action {
  std::string Name() const override { return "Describe."; };
  void Execute(game::State* state) override { 
    std::cout << state->current_scene->Description() << std::endl;
  }
};

class EnterMineAction : public game::Action {
  std::string Name() const override { return "Step into The Mine."; };
  void Execute(game::State* state) override { state->ToScene("The Mine"); }
};

class GoToCastleAction : public game::Action {
  std::string Name() const override { return "Go to The Castle"; };
  void Execute(game::State* state) override { state->ToScene("The Mine"); }
};

class OpeningScene : public game::Scene {
 public:
  std::string Description() const override {
    return R"(You are a Gem Hunter!
Princess Krystalia seeks the best Gem in all of the land.

She offers her hand in marriage to the one who rises to the challenge.

Behind you, The Castle sparkles against blue sky, standing tall and majestically adorned.
In front of you, the dark darkness of The Mine...)";
  }
  std::vector<game::Action*> Actions() const override {
    return {
        new DescribeAction(),
        new EnterMineAction(),
        new GoToCastleAction(),
    };
  }
};
}  // namespace

int main() {
  OpeningScene first;
  game::State state(&first);
  state.scene_map["Opening"] = &first;
  state.scene_map["The Mine"] = &first;
  state.scene_map["The Castle"] = &first;

  state.ToScene("Opening");

  while (true) {
    std::string input;
    std::cout << "\nOptions: " << std::endl;
    state.current_scene->PrintOptions();
    std::cout << ">>> ";
    std::cout.flush();
    std::getline(std::cin, input);
    state.current_scene->TryInput(input, &state);
  }
  return 0;
}
