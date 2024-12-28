#ifndef TEXTADVENTURE_SCENE_H
#define TEXTADVENTURE_SCENE_H

#include <string>
#include <vector>

#include "textadventure/action.h"

namespace game {

class Action;
class State;

class Scene {
 public:
  virtual ~Scene() = default;

  // Return the description of the scene.
  virtual std::string Description() const = 0;

  void PrintDescription() const;

  // Retrieve possible actions.
  virtual std::vector<Action*> Actions() const = 0;

  void PrintOptions() const;

  void TryInput(const std::string& input, State* state);

  virtual void Reaction();

 protected:
  // Protected constructor to ensure the class remains abstract
  Scene() = default;
};

}  // namespace game

#endif  // TEXTADVENTURE_SCENE_H