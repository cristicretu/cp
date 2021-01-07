#include <bits/stdc++.h>

const int M = 1e9 + 7, mxn = 1e3 + 2;

int n, dp[mxn][mxn];
std::string s[mxn];

int main() {
  std::ios_base::sync_with_stdio(false);

  std::cin >> n;
  for (int i = 0; i < n; ++i) std::cin >> s[i];

  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i) dp[i][j] += dp[i - 1][j];
      if (j) dp[i][j] += dp[i][j - 1];
      dp[i][j] %= M;
      if (s[i][j] == '*') dp[i][j] = 0;
    }
  }

  std::cout << dp[n - 1][n - 1];
  return 0;
}
