#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

int getPriority(char c) {
  if (c >= 'a') {
    return c - 'a' + 1;
  }

  return c - 'A' + 27;
}

int main(int argc, char** argv) {
  std::ifstream f("input.in");
  if (argc > 1) {
    f = std::ifstream("example.in");
  }

  std::string line;
  int result = 0;
  while (std::getline(f, line)) {
    std::unordered_set<char> first;
    std::unordered_set<char> second;

    for (int i = 0; i < line.length() / 2; ++i) {
      first.insert(line.at(i));
    }
    for (int i = line.length() / 2; i < line.length(); ++i) {
      if (first.find(line.at(i)) != first.end() && 
          second.find(line.at(i)) == second.end()) {
        std::cout << line.at(i) << getPriority(line.at(i)) << std::endl;
        result += getPriority(line.at(i));
      }
      second.insert(line.at(i));
    }
  }

  std::cout << result << std::endl;
}
