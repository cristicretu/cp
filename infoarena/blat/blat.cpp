#include <bits/stdc++.h>

std::ifstream fin("blat.in");
std::ofstream fout("blat.out");

const int mxn = 1e2 + 5;

int n, m, k;

int mat[mxn][mxn], sum[mxn];

int main() {
  fin >> m >> n >> k;
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= m; ++j) {
      fin >> mat[i][j];
      sum[j] += mat[i][j];
    }
  }

  std::sort(sum + 1, sum + m + 1);
  for (int i = 1; i <= k; ++i) {
    std::sort(mat[i] + 1, mat[i] + m + 1);
  }

  int mx = -1e9, mn = 1e9;
  for (int i = 1; i <= k; ++i) {
    int ans = 0;
    for (int j = 1; j <= n; ++j) ans += mat[i][j];

    mn = std::min(mn, ans);

    ans = 0;
    for (int j = m - n + 1; j <= m; ++j) ans += mat[i][j];

    mx = std::max(mx, ans);
  }

  int smx(0), smn(0);
  for (int i = 1; i <= n; ++i) smn += sum[i];
  for (int i = m; i >= m - n + 1; --i) smx += sum[i];

  fout << smx << '\n' << smn << '\n' << mx << '\n' << mn << '\n';
  return 0;
}
