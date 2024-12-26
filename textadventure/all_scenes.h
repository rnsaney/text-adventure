#ifndef TEXTADVENTURE_ALL_SCENES_H
#define TEXTADVENTURE_ALL_SCENES_H

#include "textadventure/scene.h"
#include "textadventure/state.h"

namespace game {
namespace scenes {

Scene* Opening(game::State* state);
Scene* MineEntry(game::State* state);
Scene* Castle(game::State* state);

}  // namespace scenes
}  // namespace game

#endif  // #ifndef TEXTADVENTURE_ALL_SCENES_H
