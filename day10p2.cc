#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <memory>
#include <utility>
#include <cmath>



int main(int argc, char** argv) {
  std::ifstream f("input.in");
  if (argc > 1) {
    f = std::ifstream("example.in");
  }
  int clock = 0;
  int target = 0;
  int x = 0;
  std::string line;
  while (std::getline(f, line)) {
    if (line.at(0) == 'a') {
      if (clock == target) { 
        std::cout << std::endl;
        target += 40;
      }
      if (clock % 40 == x || clock % 40 == x + 1 || clock % 40 == x + 2) {
        std::cout << "#";
      } else {
        std::cout << ".";
      }
      ++clock;
      if (clock == target) { 
        std::cout << std::endl;
        target += 40;
      }
      if (clock % 40 == x || clock % 40 == x + 1 || clock % 40 == x + 2) {
        std::cout << "#";
      } else {
        std::cout << ".";
      }
      ++clock;
      int i = std::stoi(line.substr(5));
      x += i;
    } else {
      if (clock == target) { 
        std::cout << std::endl;
        target += 40;
      }
      if (clock % 40 == x || clock % 40 == x + 1 || clock % 40 == x + 2) {
        std::cout << "#";
      } else {
        std::cout << ".";
      }
      ++clock;
    }
  }
  std::cout << std::endl;

  return 0;
}
