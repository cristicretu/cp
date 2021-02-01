#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;

    int x = (int)((n - 2) / 3);

    if (x + (x + 1) + (x + 2) == n)
      std::cout << x << ' ' << x + 1 << ' ' << x + 2 << '\n';
    else
      std::cout << "-1\n";
  }
}