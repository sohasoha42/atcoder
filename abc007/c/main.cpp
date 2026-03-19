#include <bits/stdc++.h>
using namespace std;

int main() {
  int r, c;
  cin >> r >> c;

  int sy, sx;
  cin >> sy >> sx;
  --sy;
  --sx;

  int gy, gx;
  cin >> gy >> gx;
  --gy;
  --gx;

  vector<string> grid;
  for (int i = 0; i < r; ++i) {
    string ci;
    cin >> ci;
    grid.push_back(ci);
  }

  vector<vector<int>> d(r, vector<int>(c, -1));
  d[sy][sx] = 0;

  queue<pair<int, int>> que;
  que.push({sy, sx});

  int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

  while (que.size() > 0) {
    pair<int, int> now = que.front();
    que.pop();

    for (int i = 0; i < 4; ++i) {
      if (0 <= now.first + dy[i] && now.first + dy[i] < r &&
          0 <= now.second + dx[i] && now.second + dx[i] < c &&
          d[now.first + dy[i]][now.second + dx[i]] == -1 &&
          grid[now.first][now.second] == '.') {
        d[now.first + dy[i]][now.second + dx[i]] = d[now.first][now.second] + 1;
        que.push({now.first + dy[i], now.second + dx[i]});
      }
    }
  }
  cout << d[gy][gx] << endl;
}
