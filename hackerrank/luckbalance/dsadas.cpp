#include <bits/stdc++.h>

bool compare(const std::pair<int, bool> a, const std::pair<int, bool> b) {
  if (a.second == b.second) return a.first > b.first;
  return a.second > b.second;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int n, k;
  std::cin >> n >> k;
  std::vector<std::pair<int, bool>> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i].first >> a[i].second;

  std::sort(a.begin(), a.end(), compare);

  int ans(0);
  for (int i = 0; i < n; ++i) {
    if (a[i].second) {
      if (k) {
        k--;
        ans += a[i].first;
      } else {
        ans -= a[i].first;
      }
    } else {
      ans += a[i].first;
    }
  }

  std::cout << ans;

  // for (int i = 0; i < n; ++i) std::cout << a[i].first << ' ';
  // std::cout << std::endl;
  // for (int i = 0; i < n; ++i) std::cout << a[i].second << ' ';

  return 0;
}
