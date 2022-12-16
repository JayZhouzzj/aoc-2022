#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

int getPriority(char c) {
  if (c >= 'a') {
    return c - 'a' + 1;
  }

  return c - 'A' + 27;
}

int main(int argc, char** argv) {
  std::ifstream f("input.in");
  if (argc > 1) {
    f = std::ifstream("example.in");
  }

  std::string line;
  int result = 0;
  while (std::getline(f, line)) {
    std::string line2;
    std::getline(f, line2);
    std::string line3;
    std::getline(f, line3);
    std::unordered_set<char> first;
    std::unordered_set<char> second;
    std::unordered_set<char> third;

    for (int i = 0; i < line.length(); ++i) {
      first.insert(line.at(i));
    }
    for (int i = 0; i < line2.length(); ++i) {
      second.insert(line2.at(i));
    }
    for (int i = 0; i < line3.length(); ++i) {
      if (first.find(line3.at(i)) != first.end() && 
          second.find(line3.at(i)) != second.end() && 
          third.find(line3.at(i)) == third.end()) {
        std::cout << line3.at(i) << std::endl;
        result += getPriority(line3.at(i));
      }
      third.insert(line3.at(i));
    }
  }

  std::cout << result << std::endl;
}
