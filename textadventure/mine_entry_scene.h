#ifndef TEXTADVENTURE_MINE_ENTRY_SCENE_H
#define TEXTADVENTURE_MINE_ENTRY_SCENE_H

#include <memory>
#include <vector>

#include "textadventure/action.h"
#include "textadventure/common_actions.h"
#include "textadventure/scene.h"

namespace game {
namespace scenes {

class MineEntryScene : public game::Scene {
 public:
  MineEntryScene(game::State* state);
  std::string Name() const override;
  std::string Description() const override;
  const std::vector<ActionStruct> Actions() const override;

 private:
  game::State* _state;
};

}  // namespace scenes
}  // namespace game

#endif  // TEXTADVENTURE_MINE_ENTRY_SCENE_H