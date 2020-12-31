#include <bits/stdc++.h>

int main() {
  using namespace std;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int ans(0);
    for (int i = 1; i < s.size(); ++i)
      if (s[i] == s[i - 1] || s[i] == s[i - 2]) s[i] = '?', ++ans;
    cout << ans << '\n';
  }
  return 0;
}
