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

  int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};

  while (que.size() > 0) {
    auto [y, x] = que.front();
    que.pop();

    for (int i = 0; i < 4; ++i) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (0 <= ny && ny < r && 0 <= nx && nx < c && d[ny][nx] == -1 &&
          grid[ny][nx] == '.') {
        d[ny][nx] = d[y][x] + 1;
        que.push({ny, nx});
      }
    }
  }
  cout << d[gy][gx] << endl;
}
