#include <bits/stdc++.h>

int main() {
  using namespace std;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, d;
    cin >> n >> d;
    string ans = "";
    int i = 0;
    char c = 'a';
    while (i < n) {
      ans += c;
      if (c == 'a')
        c = 'b';
      else if (c == 'b')
        c = 'c';
      else if (c == 'c')
        c = 'a';
      i++;
    }
    cout << ans << '\n';
  }
  return 0;
}