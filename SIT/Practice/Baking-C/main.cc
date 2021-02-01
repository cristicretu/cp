#include <bits/stdc++.h>

inline bool cmp(const std::pair<int, int> a, const std::pair<int, int> b) {
  return a.second < b.second;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int current;
  std::cin >> current;

  std::vector<std::pair<int, int>> v(2);

  for (int i = 0; i < 2; ++i) {
    std::cin >> v[i].first;
    v[i].second = abs(v[i].first - current);
  }

  std::sort(v.begin(), v.end(), cmp);

  std::cout << abs(v[0].first - current) + abs(v[1].first - v[0].first);

  return 0;
}