#include <bits/stdc++.h>

const int mxn = 1e5 + 10, M = 1e9 + 7;

int dp[mxn][15];

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
    s = '*' + s;
    n++;
    for (int i = 1; i <= n; ++i)
      for (int j = 0; j <= 10; ++j) dp[i][j] = 0;

    for (int i = 1; i < 10; ++i) dp[0][1] = 1;
    for (int i = 1; i <= n; ++i) {
      if ('1' <= s[i] && s[i] <= '9')
        dp[i][s[i] - '0'] = dp[i - 1][s[i] - '0'];
      else {
        for (int j = 1; j < 10; ++j) dp[i][j] = dp[i - 1][j];
      }
      for (int j = 2; j < 10; ++j) {
        dp[i][j] = (dp[i][j] + dp[i][j - 1]) % M;
      }
    }
    std::cout << dp[n][9] << '\n';
  }
  return 0;
}
