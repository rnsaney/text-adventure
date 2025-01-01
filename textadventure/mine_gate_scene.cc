#include "textadventure/mine_gate_scene.h"

#include <array>
#include <iostream>
#include <memory>
#include <string>

#include "textadventure/action.h"
#include "textadventure/all_scenes.h"
#include "textadventure/common_actions.h"
#include "textadventure/scene.h"

namespace game {
namespace scenes {
namespace {
class TurnBackAction : public game::Action {
 public:
  std::string Name() const override { return "Turn Back"; };
  void Execute(game::State* state) override {
    state->ToScene(game::scenes::MineEntry(state));
  }
};

class FiddleWithPadlockAction : public game::Action {
 public:
  std::string Name() const override { return "Fiddle with Padlock"; };
  void Execute(game::State* state) override {
    std::cout << "The padlock digits are set to " +
                     state->MineGatePadlockDigits() + "."
              << std::endl;
    state->SetMineGatePadlockState(game::State::MineGatePadlockState::FIDDLING);
  }
};

class EnterPadlockNumberAction : public game::Action {
 public:
  EnterPadlockNumberAction(std::string digits) : _digits(digits) {}

  std::string Name() const override { return "Try " + _digits; };
  void Execute(game::State* state) override {
    state->SetMineGatePadlockDigits(_digits);
    if (_digits == "8765") {
      state->SetMineGatePadlockState(game::State::MineGatePadlockState::OPEN);
      std::cout << "*CAH-CLINK*\n"
                   "The padlock opens!!"
                << std::endl;
      state->WinGame();
    } else {
      std::cout << "Hmm. The padlock doesn't budge.." << std::endl;
      state->SetMineGatePadlockState(game::State::MineGatePadlockState::LOCKED);
    }
  }
  std::string _digits;
};

const std::vector<std::shared_ptr<EnterPadlockNumberAction>>
EnterPadlockNumberActions() {
  std::vector<std::shared_ptr<EnterPadlockNumberAction>> result = {
      std::make_shared<EnterPadlockNumberAction>("1927"),
      std::make_shared<EnterPadlockNumberAction>("3819"),
      std::make_shared<EnterPadlockNumberAction>("9671"),
      std::make_shared<EnterPadlockNumberAction>("8765"),
      std::make_shared<EnterPadlockNumberAction>("6789"),
      std::make_shared<EnterPadlockNumberAction>("5678"),
      std::make_shared<EnterPadlockNumberAction>("4287"),
      std::make_shared<EnterPadlockNumberAction>("8754"),
      std::make_shared<EnterPadlockNumberAction>("3579"),
  };
  return result;
}

class ReadLogbookAction : public game::Action {
 public:
  std::string Name() const override { return "Read Book"; };
  void Execute(game::State* state) override {
    switch (state->GatekeepersLogbookPage()) {
      case 0:
      case 1:
        std::cout << "The cover says: Gatekeeper's Log.\n"
                     "\n"
                     "You turn to the last page.\n"
                     "It reads:\n\n"
                     "I just saw 5 6 7 8 RATS!\n"
                     "Whoever you are, this is your problem now.\n"
                     "I quit."
                  << std::endl;
        state->SetGatekeepersLogbookPage(2);
        break;
      case 2:
        std::cout << "You turn to the first page.\n"
                     "It reads:\n"
                     "\n"
                     "Today is my first day as The Gatekeeper!\n"
                     "Here is a short poem to help me -remember- ;)\n"
                     "    They fall. They rise.\n"
                     "    They shoot. They shine.\n"
                     "SO excited for this job..!\n"
                     "\n"
                     "You close the book."
                  << std::endl;
        state->SetGatekeepersLogbookPage(1);
        break;
    }
  }
};
}  // namespace

MineGateScene::MineGateScene(game::State* state) : _state(state) {}

std::string MineGateScene::Name() const { return "Mine Gate"; }

std::string MineGateScene::Description() const {
  std::string desc;
  if (!_state->PlayerHasTorch()) {
    desc.append(
        "The room is pitch black. There is no option but to turn back.");
  } else {
    desc.append(
        "There is a gate ahead. Almost like a prison cell.\n"
        "On closer inspection, a 4-digit padlock fastens the door.\n"
        "There is a tunnel and slight draft coming up from behind The Gate.\n"
        "\n"
        R"(You realize, "I --must-- go deeper, the Gem is beyond this gate!")"
        "\n"
        "To the side is a small bed with a book.");
  }
  return desc;
}

std::vector<std::shared_ptr<game::Action>> MineGateScene::Actions() const {
  std::vector<std::shared_ptr<game::Action>> result;
  if (!_state->PlayerHasTorch()) {
    result.push_back(std::make_shared<TurnBackAction>());
    return result;
  }
  if (_state->GetMineGatePadlockState() ==
      game::State::MineGatePadlockState::FIDDLING) {
    auto action_array = EnterPadlockNumberActions();
    for (int i = 0; i < action_array.size(); i++) {
      result.push_back(action_array[i]);
    }
    return result;
  }
  result.push_back(std::make_shared<FiddleWithPadlockAction>());
  result.push_back(std::make_shared<ReadLogbookAction>());
  return result;
}
}  // namespace scenes
}  // namespace game