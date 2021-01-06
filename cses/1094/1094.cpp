/**
 *    author: etohirse
 *    created: 06.01.2021 15:17:44
 **/
#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  long long n, cnt = 0;
  std::cin >> n;
  std::vector<long long> v(n + 1);
  std::cin >> v[0];
  for (int i = 1; i < n; ++i) {
    std::cin >> v[i];
    if (v[i] < v[i - 1]) {
      while (v[i] != v[i - 1]) v[i]++, cnt++;
    }
  }
  std::cout << cnt;
  return 0;
}
