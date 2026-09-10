#include <bits/stdc++.h>
using namespace std;

unsigned count(vector<string> line) {
  unsigned count = 0;
  for (auto w : line) {
    count += w.size();
  }
  return count;
}

int main() {
  freopen("word.in", "r", stdin);
  // the following line creates/overwrites the output file
  freopen("word.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  unsigned n, k;
  cin >> n >> k;

  vector<string> vs(n);

  for (auto &s : vs) {
    cin >> s;
  }

  //   for (auto x : vs)
  //     cout << x << ' ';
  //   cout << '\n';

  vector<vector<string>> lines;
  for (auto s : vs) {
    // cout << "this is " << s << endl;

    if (!lines.empty() && count(lines.back()) + s.size() <= k) {
      lines.back().push_back(s);
    } else {
      vector<string> line;
      line.push_back(s);
      lines.push_back(line);
    }
  }

  string res = "";
  for (auto line : lines) {
    for (auto w : line) {
      res += w + ' ';
    }
    res.pop_back(); //  remove extra space
    res += '\n';
  }

  cout << res;
}