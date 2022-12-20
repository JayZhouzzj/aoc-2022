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

int main(int argc, char** argv) {
  std::ifstream f("input.in");
  int n = 99;
  if (argc > 1) {
    f = std::ifstream("example.in");
    n = 5;
  }
  std::string line;
  std::vector<std::vector<int>> grid;
  while (std::getline(f, line)) {
    std::vector<int> curr;
    for (char c : line) {
      curr.push_back(c - '0');
    }
    grid.push_back(std::move(curr));
  }
  std::vector<std::vector<int>> counts(n, std::vector<int>(n));
  for (int i = 0; i < n; ++i) {
    int max = -1;
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] > max) { 
        counts[i][j] = 1; 
        max = grid[i][j];
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    int max = -1;
    for (int j = n - 1; j >= 0; --j) {
      if (grid[i][j] > max) { 
        counts[i][j] = 1; 
        max = grid[i][j];
      }
    }
  }
  for (int j = 0; j < n; ++j) {
    int max = -1;
    for (int i = 0; i < n; ++i) {
      if (grid[i][j] > max) { 
        counts[i][j] = 1; 
        max = grid[i][j];
      }
    }
  }
  for (int j = 0; j < n; ++j) {
    int max = -1;
    for (int i = n; i >= 0; --i) {
      if (grid[i][j] > max) { 
        counts[i][j] = 1; 
        max = grid[i][j];
      }
    }
  }

  int result = 0;
  for (const auto& v : grid) {
    for (int count : v) { result += count; }
  }
  std::cout << result << std::endl;

  return 0;
}
