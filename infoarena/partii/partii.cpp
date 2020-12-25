/**
 *    author: etohirse
 *    created: 25.12.2020 14:07:54
 **/
#include <fstream>

std::ifstream fin("partii.in");
std::ofstream fout("partii.out");

const int mxn = 1e3 + 2;
int a[mxn][mxn], b[mxn][mxn], c[mxn][mxn], d[mxn][mxn], e[mxn][mxn];

int main() {
  int n, m, ans(0);
  fin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      b[i][j] = c[i][j] = 1;
      fin >> a[i][j];
      if (a[i][j] > a[i - 1][j]) b[i][j] += b[i - 1][j];
      if (a[i][j] > a[i][j - 1]) c[i][j] += c[i][j - 1];
    }
  for (int i = n; i >= 1; --i)
    for (int j = m; j >= 1; --j) {
      d[i][j] = e[i][j] = 1;
      if (a[i][j] > a[i + 1][j]) d[i][j] += d[i + 1][j];
      if (a[i][j] > a[i][j + 1]) e[i][j] += e[i][j + 1];
      ans = std::max(ans, b[i][j] + c[i][j] + d[i][j] + e[i][j] - 3);
    }
  fout << ans;
  return 0;
}
