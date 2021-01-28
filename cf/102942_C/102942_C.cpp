#include <bits/stdc++.h>

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> v(n);
  for (auto& i : v) std::cin >> i;
  std::sort(v.begin(), v.end());

  int i = 0, j = n - 1, ans = 0;
  while (i <= j) {
    if (v[j] >= k)
      ++ans, --j;
    else if (v[i] + v[j] >= k && i != j)
      ++i, --j, ++ans;
    else
      ++i;
  }
  std::cout << ans << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
