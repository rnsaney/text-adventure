#include <map>
#include <string>

#include "textadventure/action.h"
#include "textadventure/scene.h"
#include "textadventure/state.h"

namespace game {
namespace actions {

Action* Describe();
Action* EnterMine();
Action* GoToCastle();

}  // namespace actions
}  // namespace game