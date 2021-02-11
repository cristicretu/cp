#include <bits/stdc++.h>

int solve() {
  int n, k, p;
  std::cin >> n >> k >> p;

  int a[n][k], dp[n + 1][(n * k) + 1];

  memset(dp, 0xc0, sizeof(dp));
  dp[0][0] = 0;

  for (int i = 0; i < n; ++i) {
    memcpy(dp[i + 1], dp[i], sizeof(dp[0]));
    for (int j = 0, s = 0; j < k; ++j) {
      std::cin >> a[i][j];

      s += a[i][j];

      for (int l = 0; (l + j + 1) <= p; ++l) {
        dp[i + 1][l + j + 1] = std::max(dp[i][l] + s, dp[i + 1][l + j + 1]);
      }
    }
  }

  return dp[n][p];
}

int main() {
  using namespace std;

  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": " << solve() << '\n';
  }

  return 0;
}