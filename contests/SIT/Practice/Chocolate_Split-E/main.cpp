#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--) {
    unsigned long long k;
    std::cin >> k;

    std::cout << (k / 2 + 1) * (k - k / 2 + 1) << '\n';
  }
}