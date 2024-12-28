#ifndef TEXTADVENTURE_CASTLE_SCENE_H
#define TEXTADVENTURE_CASTLE_SCENE_H

#include "textadventure/action.h"
#include "textadventure/all_actions.h"
#include "textadventure/scene.h"

namespace game {
namespace scenes {

class CastleScene : virtual public game::Scene {
 public:
  CastleScene(game::State* state);
  std::string Description() const override;
  std::vector<Action*> Actions() const override;
  void Reaction() override;

 private:
  void GuardSpeaks() const;

  game::State* _state;
  int step = 1;
};

}  // namespace scenes
}  // namespace game

#endif  // TEXTADVENTURE_CASTLE_SCENE_H