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
  const static long field = 13 * 7 * 3 * 19 * 5 * 2 * 11 * 17;
  std::list<long> items;
  int mod;
  int trueThrow;
  int falseThrow;
  std::vector<Monkey>* monkeys = nullptr;
  void (*updateWorry)(long&);

  long count = 0;
  Monkey(std::list<long> items, int mod, int trueThrow, int falseThrow, 
      void (*updateWorry)(long&)):
      items{std::move(items)}, mod{mod}, 
      trueThrow{trueThrow}, falseThrow{falseThrow},
      updateWorry{updateWorry} {}
  bool test(long item) { return item % mod == 0; }
  void inspect() {
    for (long item : items) {
      ++ count;
      updateWorry(item);
      item %= field;
      if (test(item)) { (*monkeys)[trueThrow].items.push_back(item); }
      else { (*monkeys)[falseThrow].items.push_back(item); }
    }
    items.clear();
  }
};

int main(int argc, char** argv) {
  std::vector<Monkey> monkeys{
    {{71, 56, 50, 73}, 13, 1, 7, [](long& worry){ worry *= 11; }},
    {{70, 89, 82}, 7, 3, 6, [](long& worry){ worry += 1; }},
    {{52, 95}, 3, 5, 4, [](long& worry){ worry *= worry; }},
    {{94, 64, 69, 87, 70}, 19, 2, 6, [](long& worry){ worry += 2; }},
    {{98, 72, 98, 53, 97, 51}, 5, 0, 5, [](long& worry){ worry += 6; }},
    {{79}, 2, 7, 0, [](long& worry){ worry += 7; }},
    {{77, 55, 63, 93, 66, 90, 88, 71}, 11, 2, 4, [](long& worry){ worry *= 7; }},
    {{54, 97, 87, 70, 59, 82, 59}, 17, 1, 3, [](long& worry){ worry += 8; }},
  };
  if (argc > 1) {
    monkeys = std::vector<Monkey>{
      {{79, 98}, 23, 2, 3, [](long& worry){ worry *= 19; }},
      {{54, 65, 75, 74}, 19, 2, 0, [](long& worry){ worry += 6; }},
      {{79, 60, 97}, 13, 1, 3, [](long& worry){ worry *= worry; }},
      {{74}, 17, 0, 1, [](long& worry){ worry += 3; }}
    };
  }
  for (auto& monkey : monkeys) { monkey.monkeys = (&monkeys); }
  for (int i = 0; i < 10000; ++i) {
    for (auto& monkey : monkeys) { monkey.inspect(); }
    // std::cout << i << std::endl;
    // for (auto& monkey : monkeys) {
    //   for (long item : monkey.items) {
    //     std::cout << item << " ";
    //   }
    //   std::cout << std::endl;
    // }
  }
  std::vector<long> result;
  for (auto& monkey : monkeys) {
    result.push_back(monkey.count);
  }
  std::sort(result.begin(), result.end());
  for (int count : result) {
    std::cout << count << " ";
  }
  std::cout << std::endl;

  return 0;
}
