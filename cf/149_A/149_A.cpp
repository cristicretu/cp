#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  using namespace std;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0;
    for (int i = 0; i + 1 < n; ++i) {
      long long u = a[i], v = a[i + 1];
      if (u > v) swap(u, v);
      while (2 * u < v) {
        ++ans;
        u *= 2;
      }
    }

    cout << ans << '\n';
  }
  return 0;
}
