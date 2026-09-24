#include <iostream>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

#include "debug.h"

// Toggle debug output with:  g++ -std=c++17 -DLOCAL main.cpp -o main
#ifdef LOCAL
#define dbg(x) std::cerr << #x << " = " << (x) << '\n'
#else
#define dbg(x)
#endif

int main() {
  std::vector<int> v = {1, 2, 3};
  std::map<std::string, std::vector<std::pair<int, int>>> m = {
      {"a", {{1, 2}, {3, 4}}}, {"b", {}}};
  std::set<int> s = {5, 3, 9};
  std::unordered_map<int, std::string> um = {{1, "one"}, {2, "two"}};
  std::tuple<int, std::string, double> t = {1, "hi", 2.5};
  std::vector<std::vector<int>> grid = {{1, 2}, {3, 4}, {5, 6}};

  std::cout << v << '\n';
  std::cout << m << '\n';
  std::cout << s << '\n';
  std::cout << um << '\n';
  std::cout << t << '\n';
  std::cout << grid << '\n';

  dbg(v);
  dbg(grid);

  return 0;
}