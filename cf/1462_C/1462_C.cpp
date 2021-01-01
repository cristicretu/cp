#include <bits/stdc++.h>

int main() {
  using namespace std;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n > 45)
      cout << "-1\n";
    else {
      int last = 9;
      string ans;
      while (n > last) {
        ans = char('0' + last) + ans;
        n -= last;
        last--;
      }
      if (n > 0) ans = char('0' + n) + ans;
      cout << ans << '\n';
    }
  }
  return 0;
}