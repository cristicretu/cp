#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int a, b, dir[4] = {0};  // 0-1 = U,D; 2-3 = L,R
    std::cin >> a >> b;
    std::string s;
    std::cin >> s;

    int u = 0, d = 0, r = 0, l = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == 'U')
        u++;
      else if (s[i] == 'L')
        l++;
      else if (s[i] == 'D')
        d++;
      else
        r++;
    }
    if (-l <= a && a <= r && -d <= b && b <= u)
      std::cout << "YES\n";
    else
      std::cout << "NO\n";
  }
  return 0;
}
