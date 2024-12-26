#ifndef TEXTADVENTURE_STATE_H
#define TEXTADVENTURE_STATE_H

#include <map>

#include "textadventure/scene.h"

namespace game {

class Scene;

class State {
 public:
  State(Scene* first_scene);
  ~State();

  // Go to the scene by name if it exists.
  void ToScene(const std::string& scene_name);

  Scene* current_scene;
  std::map<std::string, game::Scene*> scene_map;
};

}  // namespace game

#endif  // TEXTADVENTURE_STATE_H