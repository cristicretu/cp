#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    int par = 0, impar = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      std::cin >> x;
      if (x == 1) {
        impar++;
      } else {
        par++;
      }
    }
    if ((impar + 2 * par) % 2 != 0) {
      std::cout << "NO\n";
    } else {
      int s = (impar + 2 * par) / 2;
      if (s % 2 == 0 || s % 2 == 1 and impar)
        std::cout << "YES\n";
      else
        std::cout << "NO\n";
    }
  }

  return 0;
}
