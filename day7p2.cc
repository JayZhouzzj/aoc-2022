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

class Node {
 public:
  Node* parent;
  std::vector<Node> children;
  std::string name;
  int size;
  Node(std::string name): name{name} {}
  Node(Node* parent, std::string name, int size): 
      parent{parent}, name{name}, size{size} {}
};

long bfs(const Node* node, long& resref, std::vector<long>& v, long remain = -1) {
  if (node->children.size() == 0) {
    return node->size;
  }
  
  long result = 0;
  for (const auto& child : node->children) {
    result += bfs(&child, resref, v, remain);
  }
  if (result <= 100000) {
    resref += result;
  }

  if (remain != -1) {
    if (result >= remain) { 
      std::cout << result << " " << remain << std::endl;
      v.push_back(result);
    }
  }
  return result;
}

int main(int argc, char** argv) {
  std::ifstream f("input.in");
  if (argc > 1) {
    f = std::ifstream("example.in");
  }
  std::string line;
  std::getline(f, line);
  Node head("root");
  Node* curr = &head;
  while (true) {
    if (line.at(2) == 'c') {
      // cd
      if (line.at(5) == '/' && line.length() == 6) { curr = &head; }
      else if (line.at(5) == '.' && line.at(6) == '.' && line.length() == 7) { 
        curr = curr->parent;
      } else {
        std::string name = line.substr(5);
        for (auto& child : curr->children) {
          if (child.name == name && child.size == 0) {
            curr = &child;
            break;
          }
        }
      }
      if (!std::getline(f, line)) { break; }
    } else {
      // ls
      bool shouldContinue = false;
      while (std::getline(f, line)) {
        if (line.at(0) == '$') { shouldContinue = true; break; }
        if (line.substr(0, 3) == "dir") {
          // std::cout << "dir: " << line.substr(line.find(" ") + 1) << std::endl;
          curr->children.emplace_back(curr, line.substr(line.find(" ") + 1), 0);
        } else {
          int size = std::stoi(line.substr(0, line.find(" ")));
          std::string fileName = line.substr(line.find(" ") + 1);
          if (size == 0) { std::cout << fileName << "has size" << std::endl; }
          curr->children.emplace_back(curr, fileName, size);
        }
      }
      if (shouldContinue) {
        continue;
      } else {
        break;
      }
    }
  }

  long resref = 0;
  std::vector<long> v;
  long top = bfs(&head, resref, v);
  long remain = 30000000 - (70000000 - top);
  resref = 0;
  bfs(&head, resref, v, remain);
  std::sort(v.begin(), v.end());
  std::cout << "remain: " << remain << std::endl;
  for (const auto& value : v) { std::cout << value << " "; };
  std::cout << std::endl;
  std::cout << v[0] << std::endl;

  return 0;
}
