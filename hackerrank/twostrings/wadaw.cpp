#include <bits/stdc++.h>

void solve() {
  std::string a, b;
  std::unordered_map<char, int> mp;
  std::cin >> a >> b;
  for (char d : a) {
    mp[d]++;
  }
  for (char d : b) {
    if (mp[d]) {
      std::cout << "YES\n";
      return;
    }
  }
  std::cout << "NO\n";
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
