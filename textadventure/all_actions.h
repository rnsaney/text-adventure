#ifndef TEXTADVENTURE_ALL_ACTIONS_H
#define TEXTADVENTURE_ALL_ACTIONS_H

#include "textadventure/action.h"

namespace game {
namespace actions {

Action* Describe();
Action* EnterMine();
Action* GoToCastle();
Action* ShowGem();

}  // namespace actions
}  // namespace game

#endif  // TEXTADVENTURE_ALL_ACTIONS_H
