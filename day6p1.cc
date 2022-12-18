#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>

int main(int argc, char** argv) {
  std::ifstream f("input.in");
  if (argc > 1) {
    f = std::ifstream("example.in");
  }
  std::string line;
  std::getline(f, line);
  std::unordered_map<char, int> m;
  for (int i = 0; i < line.length(); ++i) {
    if (i - 4 >= 0 && (--m[line.at(i - 4)]) == 0) {
      m.erase(line.at(i - 4));
    }
    ++m[line.at(i)];

    for (const auto& p : m) {
      std::cout << p.first << ": "  << p.second << " ";
    }
    std::cout << std::endl;

    if (m.size() == 4) {
      std::cout << i + 1 << std::endl;
      return 0;
    }
  }

  return 0;
}
