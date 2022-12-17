#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>

int overlap(int x1, int y1, int x2, int y2) {
  return (x2 <= y1 && y2 >= x1) || (x1 <= y2 && y1 >= x2);
}

int main(int argc, char** argv) {
  std::ifstream f("input.in");
  int stackCount = 9;
  int initCount = 8;
  if (argc > 1) {
    f = std::ifstream("example.in");
    stackCount = 3;
    initCount = 3;
  }
  std::vector<std::stack<char>> stacks(stackCount);
  std::vector<std::string> init;

  std::string line;
  for (int i = 0; i < initCount; ++i) {
    std::getline(f, line);
    init.push_back(line);
  }
  for (int i = initCount - 1; i >= 0; --i) {
    for (int j = 0; j < stackCount; ++j) {
      if (init[i].at(4 * j + 1) != ' ') { stacks[j].push(init[i].at(4 * j + 1)); };
    }
  }

  std::getline(f, line);
  std::getline(f, line);

  std::getline(f, line, ' ');
  while (std::getline(f, line, ' ')) {
    int count = std::stoi(line);
    std::getline(f, line, ' ');
    std::getline(f, line, ' ');
    int from = std::stoi(line) - 1;
    std::getline(f, line, ' ');
    std::getline(f, line, ' ');
    int to = std::stoi(line.substr(0, 1)) - 1;

    std::stack<int> tmp;
    for (int i = 0; i < count; ++i) {
      tmp.push(stacks[from].top());
      stacks[from].pop();
    }
    for (int i = 0; i < count; ++i) {
      stacks[to].push(tmp.top());
      tmp.pop();
    }
  }

  for (const auto& stack : stacks) {
    std::cout << stack.top();
  }
  std::cout << std::endl;
}
