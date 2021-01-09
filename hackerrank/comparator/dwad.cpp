#include <bits/stdc++.h>

bool compare(const std::pair<std::string, int> a,
             const std::pair<std::string, int> b) {
  return a.second > b.second;
  return a.first < b.first;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::vector<std::pair<std::string, int>> v(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> v[i].first >> v[i].second;
  }
  std::sort(v.begin(), v.end(), compare);
  for (int i = 0; i < n; ++i, std::cout << '\n') {
    std::cout << v[i].first << ' ' << v[i].second;
  }
  return 0;
}
