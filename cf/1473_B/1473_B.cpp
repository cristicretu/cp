#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--) {
    std::string a, b;
    std::cin >> a >> b;
    int n = a.size(), m = b.size();
    int lcm = n * m / std::__gcd(n, m);

    std::string a1 = a, b1 = b;
    for (int i = 1; i < lcm / n; ++i) a1 += a;
    for (int i = 1; i < lcm / m; ++i) b1 += b;

    std::cout << ((a1 == b1) ? a1 : "-1") << '\n';
  }
  return 0;
}
