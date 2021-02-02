#include <bits/stdc++.h>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n, ans = 0;
    std::cin >> n;

    if (n < 5) {
      for (int i = 1; i <= n; ++i)
        if (i % 3 == 0)
          ans += 3;
        else if (i % 2 == 0)
          ans += 2;
        else
          ans += 1;
      std::cout << ans << '\n';
    } else {
      int x = n / 5;
      for (int i = 5 * x + 1; i <= n; ++i) {
        if (i % 5 == 0)
          ans += 5;
        else if (i % 3 == 0)
          ans += 3;
        else if (i % 2 == 0)
          ans += 2;
        else
          ans += 1;
      }
      std::cout << 13 * x + ans << '\n';
    }
  }
}