#include <bits/stdc++.h>

std::ifstream fin("nondecreasing.in");
std::ofstream fout("nondecreasing.out");

std::string s;

long long ans = 0;

int dp[50001][26];

int main() {
  fin >> s;

  for (int i = 1; i <= s.size(); ++i) dp[0][i] = i;

  for (int i = 1; i <= s.size(); ++i) {
    for (int j = 1; j <= 26; ++j) {
      dp[i][j] = 1e9;
      dp[i][j] = std::min({dp[i][j] - 1, dp[i - 1][j - 1], dp[i - 1][j],
                           dp[i][j - 1]}) +
                 1;
    }
  }

  for (int i = 1; i <= s.size(); ++i, fout << std::endl)
    for (int j = 1; j <= 26; ++j) fout << dp[i][j] << ' ';
  return 0;
}