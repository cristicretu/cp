#include <bits/stdc++.h>

typedef long long ll;

std::ifstream fin("matcnt.in");
std::ofstream fout("matcnt.out");

const int M = 200003, mxn = 1e5 + 10;

ll dp[mxn], n;

int main() {
  fin >> n;

  dp[3] = 1;
  for (int i = 4; i <= n; ++i) {
    dp[i] = (i - 1) * dp[i - 1] % M;
    dp[i] = (dp[i] + dp[i - 3] * (i - 2) * (i - 1) / 2 % M) % M;
  }

  for (int i = 1; i <= n; ++i) dp[n] = (dp[n] * i) % M;
  fout << dp[n];
  return 0;
}
