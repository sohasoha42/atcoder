#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i < pow(2, s.length() - 1); ++i) {
    int res = 0;
    string now{s[0]};
    for (int j = 0; j < s.length() - 1; ++j) {
      if (i >> j & 1) {
        res += stoll(now);
        now = string{s[j + 1]};
      } else {
        now.append(string{s[j + 1]});
      }
    }
    res += stoll(now);
    ans += res;
  }
  cout << ans << endl;
}
