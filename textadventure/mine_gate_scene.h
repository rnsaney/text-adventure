#ifndef TEXTADVENTURE_MINE_GATE_SCENE_H
#define TEXTADVENTURE_MINE_GATE_SCENE_H

#include "textadventure/action.h"
#include "textadventure/common_actions.h"
#include "textadventure/scene.h"

namespace game {
namespace scenes {

class MineGateScene : public game::Scene {
 public:
  MineGateScene(game::State* state);
  std::string Name() const override;
  std::string Description() const override;
  std::vector<Action*> Actions() const override;

 private:
  game::State* _state;
};

}  // namespace scenes
}  // namespace game

#endif  // TEXTADVENTURE_MINE_GATE_SCENE_H