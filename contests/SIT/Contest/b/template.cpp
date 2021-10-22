#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int a, b, p;
    std::cin >> a >> b >> p;
    if (p == a || p == b) {
      std::cout << "YES\n";
    } else if (p & 1) {
      std::cout << "NO\n";
    } else if (a * b > p) {
      std::cout << "YES\n";
    }
  }
}