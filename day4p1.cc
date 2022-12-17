#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

int overlap(int x1, int y1, int x2, int y2) {
  return (x2 <= y1 && y2 >= x1) || (x1 <= y2 && y1 >= x2);
}

int main(int argc, char** argv) {
  std::ifstream f("input.in");
  if (argc > 1) {
    f = std::ifstream("example.in");
  }

  std::string line;
  int result = 0;
  int count = 0;
  while (std::getline(f, line)) {
    int comma = line.find(',');
    std::string firstpair = line.substr(0, comma);
    int x1 = std::stoi(firstpair.substr(0, firstpair.find('-')));
    int y1 = std::stoi(firstpair.substr(firstpair.find('-') + 1));
    std::string secondpair = line.substr(comma + 1);
    int x2 = std::stoi(secondpair.substr(0, secondpair.find('-')));
    int y2 = std::stoi(secondpair.substr(secondpair.find('-') + 1));
    count += overlap(x1, y1, x2, y2);
  }

  std::cout << count << std::endl;
}
