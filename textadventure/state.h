#ifndef TEXTADVENTURE_STATE_H
#define TEXTADVENTURE_STATE_H

#include <map>

#include "textadventure/scene.h"

namespace game {

class Scene;

class State {
 public:
  State() = default;
  ~State() = default;

  // Go to the scene by name if it exists.
  void ToScene(Scene* scene);
  Scene* CurrentScene() const;

 private:
  Scene* _current_scene;
};

}  // namespace game

#endif  // TEXTADVENTURE_STATE_H