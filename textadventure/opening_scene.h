#ifndef TEXTADVENTURE_OPENING_SCENE_H
#define TEXTADVENTURE_OPENING_SCENE_H

#include <memory>

#include "textadventure/action.h"
#include "textadventure/common_actions.h"
#include "textadventure/scene.h"

namespace game {
namespace scenes {

class OpeningScene : public game::Scene {
 public:
  OpeningScene(game::State* state);
  std::string Name() const override;
  std::string Description() const override;
  std::vector<std::shared_ptr<Action>> Actions() const override;

 private:
  game::State* _state;
  std::vector<std::shared_ptr<Action>> _actions;
};

}  // namespace scenes
}  // namespace game

#endif  // TEXTADVENTURE_OPENING_SCENE_H