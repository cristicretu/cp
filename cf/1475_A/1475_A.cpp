#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;

    // n /= 2;
    std::cout << (n & (n - 1) ? "YES\n" : "NO\n");
  }
  return 0;
}
