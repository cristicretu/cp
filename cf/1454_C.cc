/**
 *    author: etohirse
 *    created: 28.12.2020 10:31:26
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
    int av[n + 1], fv[n + 1] = {0};
    for (int i = 1; i <= n; ++i) std::cin >> av[i], ++fv[av[i]];
    fv[av[1]]--, fv[av[n]]--;
    std::sort(fv + 1, fv + n + 1, std::greater<int>());
    int nr = fv[1], ans(0), i(1);
    for (int i = 1; i <= n; ++i)
      if (fv[av[i]] == nr) {
        nr = av[i];
        break;
      }
    while (i <= n) {
      if (av[i] != nr) {
        ans += 1;
        while (av[i] != nr and i <= n) i++;
      }
      i++;
    }
    std::cout << ans << '\n';
  }
  return 0;
}
