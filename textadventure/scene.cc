#include "textadventure/scene.h"

#include <algorithm>
#include <iostream>
#include <map>
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
    std::cout << "[" << (i + 1) << "] " << actions[i]->Name() << std::endl;
  }
}

void Scene::TryInput(const std::string& input, State* state) {
  auto trimmed_input = Trim(input);

  auto actions = Actions();
  for (int i = 0; i < actions.size(); i++) {
    std::string candidate = std::to_string(i + 1);
    if (trimmed_input == candidate) {
      actions[i]->Execute(state);
      Reaction();
      return;
    }
  }
  std::cout << "(Unrecognized)" << std::endl;
}

void Scene::Reaction() {}
}  // namespace game