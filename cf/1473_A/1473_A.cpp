#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--) {
    int n, d;
    std::cin >> n >> d;
    std::vector<int> v(n);
    for (auto& i : v) std::cin >> i;
    std::sort(v.begin(), v.end());

    int ok = 1;
    for (int i = 0; i < n; ++i)
      if (v[i] > d) ok = 0;
    std::cout << ((ok || v[0] + v[1] <= d) ? "YES\n" : "NO\n");
  }

  return 0;
}
