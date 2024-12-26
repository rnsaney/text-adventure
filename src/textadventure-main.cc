#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> msg{"Hello", "C++",     "World",
                               "from",  "VS Code", "and the C++ extension!"};

  for (const std::string &word : msg) {
    std::cout << word << " ";
    std::cout.flush();
  }
  std::cout << std::endl;

  while (true) {
    std::string input;
    std::cout << "Enter: ";
    std::cout.flush();
    std::getline(std::cin, input);
    if (!input.empty()) {
      std::cout << "You wrote: " << input << std::endl;
      break;
    }
  }
  return 0;
}
