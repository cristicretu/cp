/**
 *    author: etohirse
 *    created: 08.01.2021 14:34:46
 **/
#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    std::string s;
    int ans = 0;
    std::cin >> s;
    for (unsigned i = 1; i < s.size(); ++i) {
      if (s[i] == s[i - 1]) ans++;
    }
    std::cout << ans << '\n';
  }
  return 0;
}
