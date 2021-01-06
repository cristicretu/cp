/**
 *    author: etohirse
 *    created: 06.01.2021 14:57:27
 **/
#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string s;
  std::cin >> s;
  unsigned curr(0), mx(0), i(0), pre(0);
  while (s[i]) {
    if (s[i] == pre)
      ++curr;
    else {
      mx = std::max(mx, curr);
      curr = 1;
      pre = s[i];
    }

    ++i;
  }
  mx = std::max(mx, curr);
  std::cout << mx;
  return 0;
}
