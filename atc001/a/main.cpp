#include <bits/stdc++.h>
using namespace std;

void dfs(pair<int, int> now, vector<string>& c, vector<vector<bool>>& visited) {
  int i, j;
  i = now.first;
  j = now.second;

  int h, w;
  h = c.size();
  w = c[0].length();

  for (int di = -1; di <= 1; ++di) {
    for (int dj = -1; dj <= 1; ++dj) {
      if (di == dj) {
        continue;
      }
      if (di == -dj) {
        continue;
      }

      int i2, j2;
      i2 = i + di;
      j2 = j + dj;

      if (0 <= i2 && i2 < h && 0 <= j2 && j2 < w && c[i2][j2] != '#' &&
          visited[i2][j2] != true) {
        visited[i2][j2] = true;
        dfs({i2, j2}, c, visited);
      }
    }
  }
}

int main() {
  int h, w;
  cin >> h >> w;

  vector<string> c;
  for (int i = 0; i < h; ++i) {
    string ci;
    cin >> ci;
    c.push_back(ci);
  }

  pair<int, int> s, g;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (c[i][j] == 's') {
        s = {i, j};
      } else if (c[i][j] == 'g') {
        g = {i, j};
      }
    }
  }

  vector<vector<bool>> visited(h, vector<bool>(w, false));
  visited[s.first][s.second] = true;
  dfs(s, c, visited);

  if (visited[g.first][g.second] == true) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
