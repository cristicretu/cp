#include <bits/stdc++.h>

std::ifstream fin("drept3.in");
std::ofstream fout("drept3.out");

const int mxn = 1e4 + 10;
int n, dp[mxn][mxn], L, C;

int main() {
  fin >> n;
  for (int i = 1; i <= n; ++i) {
    int a, b, c;
    fin >> a >> b >> c;
    L = std::max(L, a + c + 2), C = std::max(C, b + c + 2);
    dp[a + 1][b + 1]++, dp[a + 1 + c][b + 1 + c]++;
    dp[a + 1][b + 1 + c]--, dp[a + 1 + c][b + 1]--;
  }

  long long ans = 0, mx = 0;
  for (int i = 1; i <= L; ++i) {
    for (int j = 1; j <= C; ++j) {
      dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
      mx = std::max(mx, 1LL * dp[i][j]);
      ans += (dp[i][j] ? 1 : 0);
    }
  }
  fout << ans << '\n' << mx;
  return 0;
}
