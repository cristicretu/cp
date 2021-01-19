#include <bits/stdc++.h>

int solve(std::string s) {
  int n = s.size();
  char last = '*';
  int ans = 0;

  std::vector<std::pair<char, int>> v;

  for (int i = 0u; i < n; ++i) {
    if (s[i] == last)
      ans++;
    else {
      if (last != '*') v.push_back({last, ans});
      last = s[i];
      ans = 1;
    }
  }
  v.push_back({last, ans});
  ans = 0;

  ans = 0;
  for (auto i : v) ans += (i.second * (i.second + 1) / 2);
  for (int i = 1u; i < v.size() - 1; ++i) {
    if (v[i - 1].first == v[i + 1].first && v[i].second == 1)
      ans += std::min(v[i - 1].second, v[i + 1].second);
  }

  return ans;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  std::cout << solve(s);
  return 0;
}
