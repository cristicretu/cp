/**
 *    author: etohirse
 *    created: 28.12.2020 09:11:59
 **/
#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int q;
  std::cin >> q;
  while (q--) {
    int n;
    std::cin >> n;
    for (int i = 2; i <= n; ++i) std::cout << i << ' ';
    std::cout << 1 << '\n';
  }
  return 0;
}
