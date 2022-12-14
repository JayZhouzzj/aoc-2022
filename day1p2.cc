#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  std::ifstream f("input.in");
  std::string line;
  int max = 0;
  int curr = 0;
  std::vector<int> elfs;
  while (std::getline(f, line)) {
    if (line.length() == 0) {
      elfs.push_back(curr);
      curr = 0;
    }

    std::istringstream iss(line);
    int energy;
    while (iss >> energy) { curr += energy; }
  }
  elfs.push_back(curr);
  std::sort(elfs.rbegin(), elfs.rend());

  std::cout << elfs[0] << " " << elfs[1] << " " << elfs[2] << std::endl;
  std::cout << elfs[0] + elfs[1] + elfs[2] << std::endl;
}
