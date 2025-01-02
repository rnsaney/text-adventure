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

game::ActionStruct TurnBackAction() {
  return {.name = "Turn Back",
          .action_fn = [](std::shared_ptr<game::State> state) {
            state->ToScene(game::scenes::MineEntry(state.get()));
          }};
}

game::ActionStruct FiddleWithPadlockAction() {
  return {.name = "Fiddle with Padlock",
          .action_fn = [](std::shared_ptr<game::State> state) {
            std::cout << "The padlock digits are set to " +
                             state->MineGatePadlockDigits() + "."
                      << std::endl;
            state->SetMineGatePadlockState(
                game::State::MineGatePadlockState::FIDDLING);
          }};
}

game::ActionStruct EnterPadlockNumberAction(std::string digits) {
  return {.name = "Try " + digits,
          .action_fn = [digits](std::shared_ptr<game::State> state) {
            state->SetMineGatePadlockDigits(digits);
            if (digits == "8765") {
              state->SetMineGatePadlockState(
                  game::State::MineGatePadlockState::OPEN);
              std::cout << "*CAH-CLINK*\n"
                           "The padlock opens!!"
                        << std::endl;
              state->WinGame();
            } else {
              std::cout << "Hmm. The padlock doesn't budge.." << std::endl;
              state->SetMineGatePadlockState(
                  game::State::MineGatePadlockState::LOCKED);
            }
          }};
}

const std::vector<game::ActionStruct> EnterPadlockNumberActions2() {
  return {
      EnterPadlockNumberAction("1927"), EnterPadlockNumberAction("3819"),
      EnterPadlockNumberAction("9671"), EnterPadlockNumberAction("8765"),
      EnterPadlockNumberAction("6789"), EnterPadlockNumberAction("5678"),
      EnterPadlockNumberAction("4287"), EnterPadlockNumberAction("8754"),
      EnterPadlockNumberAction("3579"),
  };
}

game::ActionStruct ReadLogbookAction() {
  return {.name = "Read Book",
          .action_fn = [](std::shared_ptr<game::State> state) {
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
          }};
}
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

const std::vector<ActionStruct> MineGateScene::Actions() const {
  std::vector<game::ActionStruct> result;
  if (!_state->PlayerHasTorch()) {
    result.push_back(TurnBackAction());
    return result;
  }
  if (_state->GetMineGatePadlockState() ==
      game::State::MineGatePadlockState::FIDDLING) {
    auto action_array = EnterPadlockNumberActions2();
    for (int i = 0; i < action_array.size(); i++) {
      result.push_back(action_array[i]);
    }
    return result;
  }
  result.push_back(FiddleWithPadlockAction());
  result.push_back(ReadLogbookAction());
  return result;
}

}  // namespace scenes
}  // namespace game