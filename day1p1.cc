#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>

int main(int argc, char** argv) {
  std::ifstream f("input.in");
  std::string line;
  int max = 0;
  int curr = 0;
  while (std::getline(f, line)) {
    if (line.length() == 0) {
      max = std::max(max, curr);
      curr = 0;
    }

    std::istringstream iss(line);
    int energy;
    while (iss >> energy) { curr += energy; }
  }

  std::cout << max << std::endl;
}
