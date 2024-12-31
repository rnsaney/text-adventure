#ifndef TEXTADVENTURE_COMMON_ACTIONS_H
#define TEXTADVENTURE_COMMON_ACTIONS_H

#include "textadventure/action.h"

namespace game {
namespace actions {

Action* Describe();
Action* EnterMine();
Action* GoToCastle();
Action* GoToOpeningField();
Action* ShowGem();
Action* TakeTorch();
Action* DiveDeeper();

}  // namespace actions
}  // namespace game

#endif  // TEXTADVENTURE_COMMON_ACTIONS_H
