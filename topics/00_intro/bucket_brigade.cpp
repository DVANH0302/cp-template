#include <bits/stdc++.h>
using namespace std;

struct Item {
  pair<int, int> loc;
  int cost;
};

int main() {
  freopen("buckets.in", "r", stdin);
  freopen("buckets.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  char grid[10][10];
  string line;
  pair<int, int> b, l, r;
  for (int i = 0; i < 10; i++) {
    getline(cin, line);
    for (int j = 0; j < 10; j++) {
      grid[i][j] = line[j];

      if (grid[i][j] == 'B') {
        b = make_pair(i, j);
      } else if (grid[i][j] == 'L') {
        l = make_pair(i, j);
      } else if (grid[i][j] == 'R') {
        r = make_pair(i, j);
      }
    }
  }

  deque<Item> q;
  set<pair<int, int>> visited;
  auto lakeItem = Item{l, 0};
  q.push_back(lakeItem);
  visited.insert(lakeItem.loc);

  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};

  while (!q.empty()) {
    Item item = q.front();
    q.pop_front();

    if (item.loc == b) {
      cout << item.cost - 1 << endl;
      return 0;
    }

    // adding nb
    for (int i = 0; i < 4; i++) {
      Item newItem =
          Item{make_pair(item.loc.first + dx[i], item.loc.second + dy[i]),
               item.cost + 1};
      auto [x, y] = newItem.loc;
      if ((x >= 0 && x < 10 && y >= 0 && y < 10) && (newItem.loc != r) &&
          (visited.find(newItem.loc)) == visited.end()) {
        visited.insert(newItem.loc);
        q.push_back(newItem);
      }
    }
  }

  //   for (int i = 0; i < 10; i++) {
  //     for (int j = 0; j < 10; j++) {
  //       cout << grid[i][j] << " ";
  //     }
  //     cout << endl;
  //   }
}