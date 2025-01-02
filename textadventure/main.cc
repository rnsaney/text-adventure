#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "textadventure/action.h"
#include "textadventure/all_scenes.h"
#include "textadventure/common_actions.h"
#include "textadventure/scene.h"
#include "textadventure/state.h"

int main() {
  std::shared_ptr<game::State> state = std::make_shared<game::State>();
  game::Scene* opening = game::scenes::Opening(state.get());
  state->ToScene(opening);

  while (true) {
    std::string input;
    state->CurrentScene()->PrintOptions();
    std::cout << ">>> ";
    std::cout.flush();
    std::getline(std::cin, input);
    state->CurrentScene()->TryInput(input, state);
    if (state->IsGameOver()) {
      std::cout << "\nGAME OVER\n" << std::endl;
      break;
    }
    if (state->IsGameWon()) {
      std::cout << "\nYOU WIN!\n" << std::endl;
      std::cout << "\nThis concludes The Demo. Thank you for playing!\n"
                << std::endl;
      break;
    }
  }
  return 0;
}
