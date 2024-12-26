#ifndef TEXTADVENTURE_OPENING_SCENE_H
#define TEXTADVENTURE_OPENING_SCENE_H

#include "textadventure/action.h"
#include "textadventure/all_actions.h"
#include "textadventure/scene.h"

namespace game {
namespace scenes {

class OpeningScene : public game::Scene {
 public:
  OpeningScene(game::State* state);
  std::string Description() const;
  std::vector<Action*> Actions() const;

 private:
  game::State* _state;
};

}  // namespace scenes
}  // namespace game

#endif  // TEXTADVENTURE_OPENING_SCENE_H