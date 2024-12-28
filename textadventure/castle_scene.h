#ifndef TEXTADVENTURE_CASTLE_SCENE_H
#define TEXTADVENTURE_CASTLE_SCENE_H

#include "textadventure/action.h"
#include "textadventure/all_actions.h"
#include "textadventure/scene.h"

namespace game {
namespace scenes {

class CastleScene : public game::Scene {
 public:
  std::string Description() const override;
  std::vector<Action*> Actions() const override;
};

}  // namespace scenes
}  // namespace game

#endif  // TEXTADVENTURE_CASTLE_SCENE_H