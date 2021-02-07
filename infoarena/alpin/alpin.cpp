#include <bits/stdc++.h>

std::ifstream fin("alpin.in");
std::ofstream fout("alpin.out");

const int mxn = 1e3 + 50, dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int n, a[mxn][mxn], mat[mxn][mxn], lmax;

inline bool ok(int i, int j) { return i && j && i <= n && j <= n; }

inline int dfs(int i, int j) {
  if (mat[i][j]) return mat[i][j];
  int ans = 1;
  for (int k = 0; k < 4; ++k) {
    int ni = i + dx[k], nj = j + dy[k];
    if (ok(ni, nj) && a[ni][nj] > a[i][j]) ans = std::max(ans, dfs(ni, nj) + 1);
  }
  mat[i][j] = ans;
  return mat[i][j];
}

int main() {
  fin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      fin >> a[i][j];
    }
  }

  int startx, starty;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      int x = dfs(i, j);
      if (lmax < x) {
        lmax = x;
        startx = i, starty = j;
      }
    }
  }

  fout << lmax << '\n';
  for (int i = lmax; i > 0; --i) {
    fout << startx << ' ' << starty << '\n';
    for (int k = 0; k < 4; ++k) {
      int ni = startx + dx[k], nj = starty + dy[k];
      if (mat[startx][starty] == mat[ni][nj] + 1 &&
          a[startx][starty] < a[ni][nj]) {
        startx = ni, starty = nj;
        break;
      }
    }
  }

  return 0;
}
