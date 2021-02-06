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

  for (int i = 1; i <= s.size(); ++i) {
    v[i] = s[i] - 'a' + 1;
  }

  for (int i = 1; i <= 26; ++i) {
    for (int j = 1; j <= s.size(); ++j) {
      dp[i][j] = i;
    }
  }

  for (int i = 1; i <= 26; ++i) {
    dp[i][1] = calc(i, v[i]);
    for (int j = 2; j <= s.size(); ++j) {
      for (int k = 1; k <= i; ++k)
        dp[i][j] = std::min(dp[k][j - 1] + calc(i, v[j]), k);
    }
  }
  int ans = 1e9;
  for (int i = 1; i <= 26; ++i) ans = std::min(ans, dp[i][s.size()]);
  fout << ans;
  return 0;
}