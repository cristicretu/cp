#include <bits/stdc++.h>

std::ifstream fin("acces.in");
std::ofstream fout("acces.out");

int n, m, a[1001][1001], dp[1001][1001];
int q, x, y;

int main() {
  fin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      fin >> a[i][j];
      a[i][j] = (a[i][j] == 1 ? 0 : 1);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j] == 0)
        dp[i][j] =
            std::min(dp[i - 1][j], std::min(dp[i - 1][j - 1], dp[i][j - 1]));
      if (a[i][j] == 1) {
        dp[i][j] = a[i][j];
        if (a[i][j - 1] == 1) dp[i][j] += dp[i][j - 1];
        if (a[i - 1][j] == 1) dp[i][j] += dp[i - 1][j];
        if (a[i][j - 1] == 1 && a[i - 1][j] == 1) dp[i][j] -= dp[i - 1][j - 1];
      }
    }
  }
  fin >> q;
  while (q--) {
    fin >> x >> y;
    fout << dp[x][y] << '\n';
  }

  // for (int i = 1; i <= n; ++i, fout << std::endl)
  // for (int j = 1; j <= m; ++j) fout << dp[i][j] << ' ';

  return 0;
}
