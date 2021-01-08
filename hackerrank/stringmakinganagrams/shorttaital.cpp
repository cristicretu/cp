#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);

  std::string a, b;
  std::cin >> a >> b;
  std::map<char, int> mp;
  for (char d : a) {
    ++mp[d];
  }
  for (char d : b) {
    --mp[d];
  }
  int n = std::max(a.size(), b.size());
  int ans = 0;
  for (int i = 0; i < 26; ++i) {
    ans += abs(mp[i + 'a']);
  }
  std::cout << ans;
  return 0;
}
