#include <bits/stdc++.h>

std::ifstream fin("poly2.in");
std::ofstream fout("poly2.out");

const int M = 30103;

int ans[505][1005], dp[505][1005], n;
int main() {
  fin >> n;
  dp[1][1] = 1, ans[1][1] = 1;
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= n; ++j)
      dp[i][j] = (dp[i - 1][j - 1] + ans[i - 1][j]) % M;
    for (int j = n; j >= 1; --j) ans[i][j] = (dp[i][j] + ans[i][j + 1]) % M;
  }
  fout << ans[n][1];
  return 0;
}
