#include <bits/stdc++.h>

std::ifstream fin("deceeu.in");
std::ofstream fout("deceeu.out");

const int mxn = 2e2 + 2, M = 1e9 + 7;

int dp[mxn][mxn];

void add(int &x, int y) {
  x += y;
  if (x >= M) x -= M;
  if (x < 0) x += M;
}

int main() {
  using namespace std;
  int t;
  fin >> t;
  while (t--) {
    string s;
    fin >> s;
    s = '*' + s;
    int n = s.size(), ans = 0;

    for (int k = 1; k <= n; ++k) {
      memset(dp, 0, sizeof(dp));
      for (int i = 1; i < k; ++i) {
        if (s[i] == s[k]) dp[i][k] = 1;
        for (int j = k; j <= n; ++j) {
          add(dp[i][j], dp[i][j - 1]);
          add(dp[i][j], dp[i - 1][j]);
          if (s[i] != s[j]) add(dp[i][j], -dp[i - 1][j - 1]);
        }
      }
      add(ans, dp[k - 1][n]);
    }
    fout << ans << '\n';
  }
  return 0;
}