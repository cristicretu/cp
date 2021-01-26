#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;

    std::cout << (n % 2020 <= n / 2020 ? "YES\n" : "NO\n");
  }
  return 0;
}
