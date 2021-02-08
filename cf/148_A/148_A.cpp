#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    std::string s;
    std::cin >> s;

    for (int i = 0; i < s.size(); i += 2) {
      if (s[i] == 'a')
        s[i] = 'b';
      else
        s[i] = 'a';
    }
    for (int j = 1; j < s.size(); j += 2) {
      if (s[j] == 'z')
        s[j] = 'y';
      else
        s[j] = 'z';
    }
    std::cout << s << '\n';
  }
  return 0;
}
