/**
 *    author: etohirse
 *    created: 28.12.2020 09:35:36
 **/
#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> av(n + 1), fv(n + 1);
    for (int i = 0; i < n; ++i) {
      std::cin >> av[i];
      fv[av[i]]++;
    }
    int ans = -1, mn = 3e6;
    for (int i = 0; i < n; ++i)
      if (fv[av[i]] == 1 && av[i] < mn) {
        mn = av[i];
        ans = i + 1;
      }
    std::cout << ans << '\n';
  }
  return 0;
}
