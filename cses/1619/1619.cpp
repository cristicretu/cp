#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::set<std::array<int, 2>> s;
  for (int i = 0; i < n; ++i) {
    int a, b;
    std::cin >> a >> b;
    s.insert({2 * a, 1});
    s.insert({2 * b + 1, -1});
  }
  int ans = 0, c = 0;
  for (std::array<int, 2> a : s) {
    c += a[1];
    ans = std::max(ans, c);
  }
  std::cout << ans;
  return 0;
}
