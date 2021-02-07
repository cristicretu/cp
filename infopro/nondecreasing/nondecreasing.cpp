#include <bits/stdc++.h>

std::ifstream fin("nondecreasing.in");
std::ofstream fout("nondecreasing.out");

std::string s;

long long ans = 0;

int v[50001];

int dp[26][50001];

int calc(int i, int j) {
  if (i != j) return i + j;
  return 0;
}

int main() {
  fin >> s;
  int n = s.size();

  s = '*' + s;
  for (int i = 1; i <= n; ++i) {
    v[i] = s[i] - 'a' + 1;
  }

  for (int i = 1; i <= 26; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[i][j] = i;
    }
  }

  for (int i = 1; i <= 26; ++i) {
    dp[i][1] = calc(i, v[i]);
    for (int j = 2; j <= n; ++j) {
      for (int k = 1; k <= i; ++k)
        dp[i][j] = std::min(dp[k][j - 1] + calc(i, v[j]), dp[i][j]);
    }
  }
  int ans = 1e9;
  for (int i = 1; i <= 26; ++i) ans = std::min(i, dp[i][n]);
  // fout << ans;
  for (int i = 1; i <= 26; ++i, fout << std::endl) {
    for (int j = 1; j <= n; ++j) {
      fout << dp[i][j] << ' ';
    }
  }
  return 0;
}