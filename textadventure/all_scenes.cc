#include "textadventure/all_scenes.h"

#include "textadventure/castle_scene.h"
#include "textadventure/mine_entry_scene.h"
#include "textadventure/mine_gate_scene.h"
#include "textadventure/opening_scene.h"
#include "textadventure/scene.h"

namespace game {
namespace scenes {

Scene* Opening(game::State* state) {
  static game::scenes::OpeningScene s;
  return &s;
}
Scene* MineEntry(game::State* state) {
  static game::scenes::MineEntryScene s(state);
  return &s;
}
Scene* Castle(game::State* state) {
  static game::scenes::CastleScene s(state);
  return &s;
}
Scene* MineGate(game::State* state) {
  static game::scenes::MineGateScene s(state);
  return &s;
}

}  // namespace scenes
}  // namespace game
