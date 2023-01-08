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

class Monkey {
public:
  std::list<int> items;
  int mod;
  int trueThrow;
  int falseThrow;
  std::vector<Monkey>* monkeys = nullptr;
  void (*updateWorry)(int&);

  int count = 0;
  Monkey(std::list<int> items, int mod, int trueThrow, int falseThrow, 
      void (*updateWorry)(int&)):
      items{std::move(items)}, mod{mod}, 
      trueThrow{trueThrow}, falseThrow{falseThrow},
      updateWorry{updateWorry} {}
  bool test(int item) { return item % mod == 0; }
  void inspect() {
    for (int item : items) {
      ++ count;
      updateWorry(item);
      item /= 3;
      if (test(item)) { (*monkeys)[trueThrow].items.push_back(item); }
      else { (*monkeys)[falseThrow].items.push_back(item); }
    }
    items.clear();
  }
};

int main(int argc, char** argv) {
  std::vector<Monkey> monkeys{
    {{70, 89, 82}, 7, 3, 6, [](int& worry){ worry += 1; }},
    {{52, 95}, 3, 5, 4, [](int& worry){ worry *= worry; }},
    {{94, 64, 69, 87, 70}, 19, 2, 6, [](int& worry){ worry += 2; }},
    {{98, 72, 98, 53, 97, 51}, 5, 0, 5, [](int& worry){ worry += 6; }},
    {{79}, 2, 7, 0, [](int& worry){ worry += 7; }},
    {{77, 55, 63, 93, 66, 90, 88, 71}, 11, 2, 4, [](int& worry){ worry *= 7; }},
    {{54, 97, 87, 70, 59, 82, 59}, 17, 1, 3, [](int& worry){ worry += 8; }},
  };
  if (argc > 1) {
    monkeys = std::vector<Monkey>{
      {{79, 98}, 23, 2, 3, [](int& worry){ worry *= 19; }},
      {{54, 65, 75, 74}, 19, 2, 0, [](int& worry){ worry += 6; }},
      {{79, 60, 97}, 13, 1, 3, [](int& worry){ worry *= worry; }},
      {{74}, 17, 0, 1, [](int& worry){ worry += 3; }}
    };
  }
  for (auto& monkey : monkeys) { monkey.monkeys = (&monkeys); }
  for (int i = 0; i < 20; ++i) {
    for (auto& monkey : monkeys) { monkey.inspect(); }
    // std::cout << i << std::endl;
    // for (auto& monkey : monkeys) {
    //   for (int item : monkey.items) {
    //     std::cout << item << " ";
    //   }
    //   std::cout << std::endl;
    // }
  }
  for (auto& monkey : monkeys) {
    std::cout << monkey.count << " ";
  }
  std::cout << std::endl;

  return 0;
}
