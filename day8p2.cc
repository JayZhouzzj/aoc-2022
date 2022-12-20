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
  for (const auto& v : grid) {
    for (int val : v) { std::cout << val; }
    std::cout << std::endl;
  }

  int max = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int score = 1;
      for (int k = 1; k < n; ++k) {
        if (j - k < 0) {
          score *= (k - 1);
          break;
        }
        if (grid[i][j - k] >= grid[i][j]) {
          score *= k;
          break;
        }
      }
      for (int k = 1; k < n; ++k) {
        if (j + k == n) {
          score *= (k - 1);
          break;
        }
        if (grid[i][j + k] >= grid[i][j]) {
          score *= k;
          break;
        }
      }
      for (int k = 1; k < n; ++k) {
        if (i - k < 0) {
          score *= (k - 1);
          break;
        }
        if (grid[i - k][j] >= grid[i][j]) {
          score *= k;
          break;
        }
      }
      for (int k = 1; k < n; ++k) {
        if (i + k == n) {
          score *= (k - 1);
          break;
        }
        if (grid[i + k][j] >= grid[i][j]) {
          score *= k;
          break;
        }
      }
      max = std::max(max, score);
    }
  }
  
  std::cout << max << std::endl;

  return 0;
}
