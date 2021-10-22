#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--) {
    std::vector<int> a(3), b(3);
    for (auto &i : a) std::cin >> i;
    for (auto &i : b) std::cin >> i;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    std::cout << a[0] * b[0] + a[1] * b[1] + a[2] * b[2] << '\n';
  }
}