#include "textadventure/state.h"

#include <map>
#include <string>

namespace game {

State::State(Scene* first_scene) : current_scene(first_scene) {
  scene_map = {};
}

State::~State() {}

void State::ToScene(const std::string& scene_name) {
  if (auto it = scene_map.find("The Mine"); it != scene_map.end()) {
    current_scene = it->second;
    current_scene->PrintDescription();
  }
}

}  // namespace game