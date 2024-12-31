#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "textadventure/action.h"
#include "textadventure/all_scenes.h"
#include "textadventure/common_actions.h"
#include "textadventure/scene.h"
#include "textadventure/state.h"

int main() {
  game::State state;
  game::Scene* opening = game::scenes::Opening(&state);
  state.ToScene(opening);

  while (true) {
    std::string input;
    state.CurrentScene()->PrintOptions();
    std::cout << ">>> ";
    std::cout.flush();
    std::getline(std::cin, input);
    state.CurrentScene()->TryInput(input, &state);
    if (state.IsGameOver()) {
      std::cout << "\nGAME OVER\n" << std::endl;
      break;
    }
  }
  return 0;
}
