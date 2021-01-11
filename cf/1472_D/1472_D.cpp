#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  while (T--) {
    int n;
    long long ans(0);
    std::cin >> n;
    std::vector<int> v(n);
    for (auto& i : v) std::cin >> i;
    std::sort(v.begin(), v.end());
    std::reverse(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
      if (i % 2 == 0) {
        if (v[i] % 2 == 0) {
          ans += v[i];
        }
      } else {
        if (v[i] % 2 == 1) {
          ans -= v[i];
        }
      }
    }
    if (ans == 0) {
      std::cout << "Tie\n";
    } else {
      std::cout << (ans > 0 ? "Alice\n" : "Bob\n");
    }
  }
  return 0;
}
