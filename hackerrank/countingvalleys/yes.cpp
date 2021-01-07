#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;

  int cnt = 0, ans = 0;
  for (char d : s) {
    if (d == 'U')
      ++cnt;
    else
      --cnt;

    if (d == 'U' && cnt == 0) ++ans;
  }

  std::cout << ans;
  return 0;
}
