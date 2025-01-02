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
  std::string Name() const override;
  std::string Description() const override;
  const std::vector<ActionStruct> Actions() const override;
};

}  // namespace scenes
}  // namespace game

#endif  // TEXTADVENTURE_OPENING_SCENE_H