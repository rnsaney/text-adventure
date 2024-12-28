#include "textadventure/state.h"

#include <map>
#include <string>

namespace game {

void State::ToScene(game::Scene* new_scene) {
  _current_scene = new_scene;
  _current_scene->PrintDescription();
}

Scene* State::CurrentScene() const { return _current_scene; }
bool State::PlayerHasGem() const { return _player_has_gem; }
bool State::IsGameOver() const { return _game_over; }
void State::GameOver() { _game_over = true; }

}  // namespace game