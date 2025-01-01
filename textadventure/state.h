#ifndef TEXTADVENTURE_STATE_H
#define TEXTADVENTURE_STATE_H

#include <map>

#include "textadventure/scene.h"

namespace game {

class Scene;

class State {
 public:
  State() = default;
  ~State() = default;

  enum class MineGatePadlockState {
    LOCKED,
    FIDDLING,
    OPEN,
  };

  // Go to the scene by name if it exists.
  void ToScene(Scene* scene);
  Scene* CurrentScene() const;
  bool PlayerHasGem() const;
  bool PlayerHasTorch() const;
  void SetPlayerHasTorch(bool has_torch);
  bool IsGameOver() const;
  void GameOver();
  bool IsGameWon() const;
  void WinGame();
  int GatekeepersLogbookPage() const;
  void SetGatekeepersLogbookPage(int page);
  const std::string& MineGatePadlockDigits() const;
  void SetMineGatePadlockDigits(const std::string& digits);
  MineGatePadlockState GetMineGatePadlockState() const;
  void SetMineGatePadlockState(MineGatePadlockState padlock_state);

 private:
  Scene* _current_scene;
  bool _player_has_gem = false;
  bool _game_over = false;
  bool _game_won = false;
  bool _player_has_torch = false;
  int _gatekeepers_logbook_page = 0;
  std::string _mine_gate_padlock_digits = "4671";
  MineGatePadlockState _mine_gate_padlock_state = MineGatePadlockState::LOCKED;
};

}  // namespace game

#endif  // TEXTADVENTURE_STATE_H