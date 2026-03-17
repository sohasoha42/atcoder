#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> xy;
  for (int i = 0; i < n; ++i) {
    int xi, yi;
    cin >> xi >> yi;
    xy.push_back(pair(xi, yi));
  }
  double ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i; j < n; ++j) {
      ans = max(ans, sqrt(pow(xy[i].first - xy[j].first, 2) +
                          pow(xy[i].second - xy[j].second, 2)));
    }
  }
  cout << ans << endl;
  return 0;
}
