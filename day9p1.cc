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
    std::unordered_set<std::pair<int, int>, hashFunction>& s, int x, int y) {
  h.first += x;
  h.second += y;
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
  } else if (h.first - t.first == 2) {
    t.second = h.second;
    t.first += 1;
  } else if (h.first - t.first == -2) {
    t.second = h.second;
    t.first -= 1;
  } else if (h.second - t.second == 2) {
    t.first = h.first;
    t.second += 1;
  } else if (h.second - t.second == -2) {
    t.first = h.first;
    t.second -= 1;
  }

  s.insert(t);
}

int main(int argc, char** argv) {
  std::ifstream f("input.in");
  if (argc > 1) {
    f = std::ifstream("example.in");
  }
  std::pair<int, int> h(0, 0);
  std::pair<int, int> t(0, 0);
  std::unordered_set<std::pair<int, int>, hashFunction> s;
  std::string line;
  while (std::getline(f, line)) {
    int step = std::stoi(line.substr(line.find(" ") + 1));
    for (int i = 0; i < step; ++i) {
      switch (line.at(0)) {
        case 'U':
          move(h, t, s, 0, 1);
          break;
        case 'D':
          move(h, t, s, 0, -1);
          break;
        case 'L':
          move(h, t, s, -1, 0);
          break;
        case 'R':
          move(h, t, s, 1, 0);
          break;
      }
    }
    std::cout << h.first << ", " << h.second << 
        "|" << t.first << t.second << std::endl;
  }

  std::cout << s.size() << std::endl;

  return 0;
}
