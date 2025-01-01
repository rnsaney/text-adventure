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
bool State::PlayerHasTorch() const { return _player_has_torch; }
void State::SetPlayerHasTorch(bool has_torch) { _player_has_torch = has_torch; }
bool State::IsGameOver() const { return _game_over; }
void State::GameOver() { _game_over = true; }
bool State::IsGameWon() const { return _game_won; }
void State::WinGame() { _game_won = true; }
int State::GatekeepersLogbookPage() const { return _gatekeepers_logbook_page; }
void State::SetGatekeepersLogbookPage(int page) {
  _gatekeepers_logbook_page = page;
}
const std::string& State::MineGatePadlockDigits() const {
  return _mine_gate_padlock_digits;
}
void State::SetMineGatePadlockDigits(const std::string& digits) {
  _mine_gate_padlock_digits = digits;
}
State::MineGatePadlockState State::GetMineGatePadlockState() const {
  return _mine_gate_padlock_state;
}
void State::SetMineGatePadlockState(MineGatePadlockState padlock_state) {
  _mine_gate_padlock_state = padlock_state;
}

}  // namespace game