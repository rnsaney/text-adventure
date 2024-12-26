#include "textadventure/all_scenes.h"

#include "textadventure/opening_scene.h"
#include "textadventure/scene.h"

namespace game {
namespace scenes {

Scene* Opening(game::State* state) {
  static game::scenes::OpeningScene s(state);
  return &s;
}
Scene* MineEntry(game::State* state) {
  static game::scenes::OpeningScene s(state);
  return &s;
}
Scene* Castle(game::State* state) {
  static game::scenes::OpeningScene s(state);
  return &s;
}

}  // namespace scenes
}  // namespace game
