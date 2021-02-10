#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int current = 1, x, y;
    std::cin >> x >> y;

    int etime = 5 * (y - 1) + 5 * (x - 1);
    int stime = 20 * (x - 1);
    if (stime < etime) {
      std::cout << stime << '\n';
    } else {
      std::cout << etime << '\n';
    }
    // std::cout << stime << ' ';
  }
}