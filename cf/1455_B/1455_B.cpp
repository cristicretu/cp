#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int x;
    std::cin >> x;

    int count = 0;
    while (count * (count + 1) / 2 < x) ++count;
    if (count * (count + 1) / 2 == x + 1) ++count;

    std::cout << count << '\n';
  }

  return 0;
}
