#ifndef TEXTADVENTURE_CASTLE_SCENE_H
#define TEXTADVENTURE_CASTLE_SCENE_H

#include <memory>
#include <vector>

#include "textadventure/action.h"
#include "textadventure/common_actions.h"
#include "textadventure/scene.h"

namespace game {
namespace scenes {

class CastleScene : virtual public game::Scene {
 public:
  CastleScene(game::State* state);
  std::string Name() const override;
  std::string Description() const override;
  std::vector<std::shared_ptr<Action>> Actions() const override;
  void Reaction() override;

 private:
  void GuardSpeaks() const;

  game::State* _state;
  int step = 1;
};

}  // namespace scenes
}  // namespace game

#endif  // TEXTADVENTURE_CASTLE_SCENE_H