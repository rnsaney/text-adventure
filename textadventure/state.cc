#include "textadventure/state.h"

#include <map>
#include <string>

namespace game {

void State::ToScene(game::Scene* new_scene) {
  _current_scene = new_scene;
  _current_scene->PrintDescription();
}

Scene* State::CurrentScene() const { return _current_scene; }

}  // namespace game