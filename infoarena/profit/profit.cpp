#include <bits/stdc++.h>

std::ifstream fin("profit.in");
std::ofstream fout("profit.out");

const int mxn = 2e3 + 1;

int n, ans = INT_MAX, v[mxn], w[mxn], dp[mxn], mn[mxn];

void change() {
  memset(mn, 0, sizeof(mn));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) dp[j] = mn[j] + abs(v[i] - w[j]);
    mn[1] = dp[1];
    for (int j = 2; j <= n; j++) mn[j] = std::min(mn[j - 1], dp[j]);
  }
  for (int j = 1; j <= n; j++) ans = std::min(ans, dp[j]);
}

int main() {
  fin >> n;
  for (int i = 1; i <= n; ++i) fin >> v[i], w[i] = v[i];
  std::sort(w + 1, w + n + 1);

  change();

  for (int i = 1; i <= n; ++i) v[i] *= -1, w[i] *= -1;
  for (int i = 1; i <= n / 2; ++i) std::swap(w[n - i + 1], w[i]);

  change();
  fout << ans;
  return 0;
}