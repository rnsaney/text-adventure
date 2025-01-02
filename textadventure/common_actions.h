#ifndef TEXTADVENTURE_COMMON_ACTIONS_H
#define TEXTADVENTURE_COMMON_ACTIONS_H

#include "textadventure/action.h"

namespace game {
namespace actions {

ActionStruct DescribeAction();
ActionStruct GoToOpeningFieldAction();
ActionStruct EnterMineAction();
ActionStruct GoToCastleAction();
ActionStruct ShowGemAction();
ActionStruct TakeTorchAction();
ActionStruct DiveDeeperAction();

}  // namespace actions
}  // namespace game

#endif  // TEXTADVENTURE_COMMON_ACTIONS_H
