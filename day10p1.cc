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
  int target = 20;
  long result = 0;
  int x = 1;
  std::string line;
  while (std::getline(f, line)) {
    if (line.at(0) == 'a') {
      clock += 2;
      if (clock == target || clock - 1 == target) { 
        result += x * target;
        target += 40;
      }
      int i = std::stoi(line.substr(5));
      x += i;
    } else {
      ++clock;
      if (clock == target) { 
        result += x * target;
        target += 40;
      }
    }
  }

  std::cout << result << std::endl;

  return 0;
}
