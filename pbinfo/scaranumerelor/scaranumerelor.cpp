#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j, std::cout << '\n') {
      for (int k = 1; k <= i; ++k) {
        std::cout << i;
      }
    }
  }
  return 0;
}
