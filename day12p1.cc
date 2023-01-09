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
#include <list>
#include <limits.h>

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;  
    }
};

int main(int argc, char** argv) {
  std::ifstream f("input.in");
  if (argc > 1) {
    f = std::ifstream("example.in");
  }
  std::string line;
  std::vector<std::vector<char>> map;
  while (std::getline(f, line)) {
    map.emplace_back(std::vector<char>(line.begin(), line.end()));
  }
  // for (const auto& v : map) {
  //   for (char c : v) {
  //     std::cout << c << " ";
  //   }
  //   std::cout << std::endl;
  // }

  std::unordered_map<std::pair<int, int>, int, pair_hash> frontier;
  std::unordered_set<std::pair<int, int>, pair_hash> result;
  int i = 0;
  int j = 0;
  while (i < map.size()) {
    j = 0;
    while (j < map[0].size()) {
      if (map[i][j] == 'S') { goto endloop; }
      ++j;
    }
    ++i;
  }
  endloop:
  int endi = 0;
  int endj = 0;
  while (endi < map.size()) {
    endj = 0;
    while (endj < map[0].size()) {
      if (map[endi][endj] == 'E') { goto endloop2; }
      ++endj;
    }
    ++endi;
  }
  endloop2:
  map[i][j] = 'a';
  map[endi][endj] = 'z';
  frontier[std::make_pair(i, j)] = 0;
  bool done = false;
  while (!done) {
    done = true;
    int min = INT_MAX;
    std::pair<int, int> minNode;
    for (const auto& pair : frontier) {
      if (result.find(pair.first) != result.end()) { continue; }
      if (pair.second < min) {
        min = pair.second;
        minNode = pair.first;
      }
    }

    int x = minNode.first;
    int y = minNode.second;
    result.insert(minNode);
    std::cout << x << " " << y << std::endl;
    for (int ii = x - 1; ii <= x + 1; ++ii) {
      for (int jj = y - 1; jj <= j + 1; ++jj) {
        if (ii != x && jj != y) { continue; }
        if (ii >= 0 && ii < map.size() && jj >= 0 && jj < map[0].size()) {
          std::pair<int, int> neighbor(ii, jj);
          int cost = 1;
          if (map[ii][jj] - map[x][y] > 1) { continue; }
          if (frontier.find(neighbor) == frontier.end() || 
              frontier[minNode] + cost < frontier[neighbor]) {
            frontier[neighbor] = frontier[minNode] + cost;
            done = false;
          }
          if (ii == endi && jj == endj) { 
            std::cout << frontier[neighbor] << std::endl;
          }
        }
      }
    }
  }

  return 0;
}
