#ifndef TEXTADVENTURE_COMMON_ACTIONS_H
#define TEXTADVENTURE_COMMON_ACTIONS_H

#include "textadventure/action.h"

namespace game {
namespace actions {

class DescribeAction : public game::Action {
 public:
  std::string Name() const override;
  void Execute(game::State* state) override;
};

class GoToOpeningFieldAction : public game::Action {
 public:
  std::string Name() const override;
  void Execute(game::State* state) override;
};

class EnterMineAction : public game::Action {
 public:
  std::string Name() const override;
  void Execute(game::State* state) override;
};

class GoToCastleAction : public game::Action {
 public:
  std::string Name() const override;
  void Execute(game::State* state) override;
};

class ShowGemAction : public game::Action {
 public:
  std::string Name() const override;
  void Execute(game::State* state) override;
};

class TakeTorchAction : public game::Action {
 public:
  std::string Name() const override;
  void Execute(game::State* state) override;
};

class DiveDeeperAction : public game::Action {
 public:
  std::string Name() const override;
  void Execute(game::State* state) override;
};

}  // namespace actions
}  // namespace game

#endif  // TEXTADVENTURE_COMMON_ACTIONS_H
