/**
 *    author: etohirse
 *    created: 24.12.2020 18:39:53
 **/
#include <fstream>

std::ifstream fin("mex2d.in");
std::ofstream fout("mex2d.out");

const int mxn = 2e3 + 5;
#define REP(i, x) for (int i = 1; i <= x; ++i)
int a[mxn][mxn], b[mxn][mxn], fv[mxn * mxn];

int main() {
  int n, m;
  fin >> n >> m;
  REP(i, n) REP(j, m) {
    fin >> a[i][j];
    int mx = std::max(b[i - 1][j], b[i][j - 1]);
    fv[a[i][j]] = !fv[a[i][j]] ? j : std::min(fv[a[i][j]], j);
    while (fv[mx] <= j and fv[mx]) mx++;
    b[i][j] = mx;
  }
  for (int i = 1; i <= n; ++i, fout << '\n') REP(j, m)
  fout << b[i][j] << ' ';
  // test asd
  return 0;
}
