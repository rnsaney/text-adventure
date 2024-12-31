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

  // Go to the scene by name if it exists.
  void ToScene(Scene* scene);
  Scene* CurrentScene() const;
  bool PlayerHasGem() const;
  bool PlayerHasTorch() const;
  void SetPlayerHasTorch(bool has_torch);
  bool IsGameOver() const;
  void GameOver();
  int GatekeepersLogbookPage() const;
  void SetGatekeepersLogbookPage(int page);

 private:
  Scene* _current_scene;
  bool _player_has_gem = false;
  bool _game_over = false;
  bool _player_has_torch = false;
  int _gatekeepers_logbook_page = 0;
};

}  // namespace game

#endif  // TEXTADVENTURE_STATE_H