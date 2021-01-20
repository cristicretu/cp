#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::string ans = "1";
    for (int i = 1; i < n; ++i)
      if ('1' + s[i] != ans[i - 1] + s[i - 1])
        ans += '1';
      else
        ans += '0';
    std::cout << ans << '\n';
  }
  return 0;
}
