#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--) {
    int w, h, n, ans = 1;
    std::cin >> w >> h >> n;
    while (w % 2 == 0) {
      w /= 2;
      ans *= 2;
    }
    while (h % 2 == 0) {
      h /= 2;
      ans *= 2;
    }
    std::cout << (ans >= n ? "YES\n" : "NO\n");
  }
  return 0;
}
