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

struct hashFunction
{
  size_t operator()(const std::pair<int , int> &x) const
  {
    return x.first ^ x.second;
  }
};

void move(std::pair<int, int>& h, std::pair<int, int>& t, 
    std::unordered_set<std::pair<int, int>, hashFunction>& s, 
    bool track = false) {
  if (h.first == t.first) {
    if (h.second - t.second == 2) {
      t.second += 1;
    } else if (t.second - h.second == 2) {
      t.second -= 1;
    }
  } else if (h.second == t.second) {
    if (h.first - t.first == 2) {
      t.first += 1;
    } else if (t.first - h.first == 2) {
      t.first -= 1;
    }
  } else if (std::abs(h.first - t.first) == 1 && 
        std::abs(h.second - t.second) == 1) {
    // do nothing
  } else {
    if (h.first > t.first) {
      ++t.first;
    } else {
      --t.first;
    }
    if (h.second > t.second) {
      ++t.second;
    } else {
      --t.second;
    }
  }

  if (track) {
    s.insert(t); 
  }
}

int main(int argc, char** argv) {
  std::ifstream f("input.in");
  if (argc > 1) {
    f = std::ifstream("example.in");
  }
  // head, 1, 2, 3, ... 9
  std::vector<std::pair<int, int>> bruh(10);

  std::unordered_set<std::pair<int, int>, hashFunction> s;
  std::string line;
  while (std::getline(f, line)) {
    int step = std::stoi(line.substr(line.find(" ") + 1));
    for (int i = 0; i < step; ++i) {
      int x = 0;
      int y = 0;
      switch (line.at(0)) {
        case 'U':
          y = 1;
          break;
        case 'D':
          y = -1;
          break;
        case 'L':
          x = -1;
          break;
        case 'R':
          x = 1;
          break;
      }
      bruh[0].first += x;
      bruh[0].second += y;
      for (int j = 0; j < 8; ++j) {
        move(bruh[j], bruh[j + 1], s);
      }
      move(bruh[8], bruh[9], s, true);
      for (int i = 0; i <= 8; ++i) {
        std::cout << bruh[i].first << " " << bruh[i].second << std::endl;
      }
      std::cout << bruh[9].first << " " << bruh[9].second << std::endl;
      std::cout << "-" << std::endl;
    }

    for (int i = 0; i <= 8; ++i) {
      std::cout << bruh[i].first << " " << bruh[i].second << std::endl;
    }
    std::cout << bruh[9].first << " " << bruh[9].second << std::endl;
    std::cout << std::endl;
  }

  std::cout << s.size() << std::endl;

  return 0;
}
