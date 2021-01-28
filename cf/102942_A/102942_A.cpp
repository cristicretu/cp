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

    int ans = 0;
    for (char d : s) {
      if (d == '1')
        ans--;
      else
        ans++;

      if (ans == 4)
        ans = 0;
      else if (ans == -1)
        ans = 3;
    }

    std::string rem = "ESWN";
    std::cout << rem[ans] << '\n';
    }

  return 0;
}
