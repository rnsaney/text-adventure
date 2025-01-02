#include "textadventure/scene.h"

#include <algorithm>
#include <iostream>
#include <map>
#include <memory>
#include <string>

namespace game {
namespace {
std::string Trim(const std::string& str) {
  std::string result = str;
  result.erase(std::remove(result.begin(), result.end(), ' '), result.end());
  return result;
}
}  // namespace

void Scene::PrintDescription() const {
  std::cout << Description() << std::endl;
}

void Scene::PrintOptions() const {
  std::cout << "\nActions (" << Name() << "):" << std::endl;
  auto actions = Actions();
  for (int i = 0; i < actions.size(); i++) {
    std::cout << "[" << (i + 1) << "] " << actions[i].name << std::endl;
  }
}

void Scene::TryInput(const std::string& input,
                     std::shared_ptr<game::State> state) {
  auto trimmed_input = Trim(input);

  std::vector<game::ActionStruct> actions = Actions();
  for (int i = 0; i < actions.size(); i++) {
    std::string candidate = std::to_string(i + 1);
    if (trimmed_input == candidate) {
      actions[i].action_fn(state);
      Reaction();
      return;
    }
  }
  std::cout << "(Unrecognized)" << std::endl;
}

void Scene::Reaction() {}
}  // namespace game