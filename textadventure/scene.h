#ifndef TEXTADVENTURE_SCENE_H
#define TEXTADVENTURE_SCENE_H

#include <memory>
#include <string>
#include <vector>

#include "textadventure/action.h"

namespace game {

class State;
struct ActionStruct;

class Scene {
 public:
  virtual ~Scene() = default;

  virtual std::string Name() const = 0;

  // Return the description of the scene.
  virtual std::string Description() const = 0;

  void PrintDescription() const;

  // Retrive possible player actions.
  virtual const std::vector<game::ActionStruct> Actions() const = 0;

  void PrintOptions() const;

  void TryInput(const std::string& input, std::shared_ptr<State> state);

  virtual void Reaction();

 protected:
  // Protected constructor to ensure the class remains abstract
  Scene() = default;
};

}  // namespace game

#endif  // TEXTADVENTURE_SCENE_H