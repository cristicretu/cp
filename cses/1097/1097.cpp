#include <bits/stdc++.h>

typedef long long ll;
const int mxn = 5e3;
int n, x[mxn];
std::array<ll, 2> dp[mxn][mxn];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin >> n;
  for (int i = 0; i < n; ++i) std::cin >> x[i];
  for (int i = n - 1; ~i; --i) {
    for (int j = i + 1; j < n; ++j) {
      std::array<ll, 2> temp;
      if (i == j) {
        temp = {x[i], 0};
      } else {
        if (dp[i + 1][j][1] + x[i] > dp[i][j - 1][1] + x[j])
          temp = {dp[i + 1][j][1] + x[i], dp[i + 1][j][0]};
        else
          temp = {dp[i][j - 1][1] + x[j], dp[i][j - 1][0]};
      }
      dp[i][j] = temp;
    }
  }
  std::cout << dp[0][n - 1][0];
  return 0;
}
