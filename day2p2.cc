#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <unordered_map>

int main(int argc, char** argv) {
  std::ifstream f("input.in");
  std::unordered_map<std::string, int> m {
    {"A X", 0 + 3},
    {"A Y", 3 + 1},
    {"A Z", 6 + 2},
    {"B X", 0 + 1},
    {"B Y", 3 + 2},
    {"B Z", 6 + 3},
    {"C X", 0 + 2},
    {"C Y", 3 + 3},
    {"C Z", 6 + 1},
  };

  std::string line;
  int score = 0;
  while (std::getline(f, line)) {
    score += m[line];
  }

  std::cout << score << std::endl;
}
