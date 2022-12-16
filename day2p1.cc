#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <unordered_map>

int main(int argc, char** argv) {
  std::ifstream f("input.in");
  std::unordered_map<std::string, int> m {
    {"A X", 3 + 1},
    {"A Y", 6 + 2},
    {"A Z", 0 + 3},
    {"B X", 0 + 1},
    {"B Y", 3 + 2},
    {"B Z", 6 + 3},
    {"C X", 6 + 1},
    {"C Y", 0 + 2},
    {"C Z", 3 + 3},
  };

  std::string line;
  int score = 0;
  while (std::getline(f, line)) {
    score += m[line];
  }

  std::cout << score << std::endl;
}
