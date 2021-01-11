#include <bits/stdc++.h>

std::ifstream fin("barbar.in");
std::ofstream fout("barbar.out");

const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}, mxn = 1e3 + 2;

std::queue<std::pair<int, int>> cords;

int n, m, mx, count, stopx, stopy, startx, starty, mat[mxn][mxn];

inline bool ok(int i, int j) { return i and j and i <= n and j <= m; }

inline void lee() {
  while (!cords.empty()) {
    int i = cords.front().first, j = cords.front().second;
    cords.pop();
    for (int k = 0; k < 4; ++k) {
      int ni = i + dx[k], nj = j + dy[k];
      if (ok(ni, nj) && mat[ni][nj] == 0 || mat[ni][nj] > 1 + mat[i][j]) {
        mat[ni][nj] = mat[i][j] + 1;
        cords.push({ni, nj});
        mx = std::max(mx, mat[ni][nj]);
      }
    }
  }
}

inline void lee1(int x, int y) {
  cords.push({x, y});
  while (!cords.empty()) {
    int i = cords.front().first, j = cords.front().second;
    cords.pop();
    for (int k = 0; k < 4; ++k) {
      int ni = i + dx[k], nj = j + dy[k];
    }
  }
}

int main() {
  fin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      char c;
      fin >> c;
      if (c == '.') {
        mat[i][j] = 0;
      } else if (c == 'I') {
        startx = i, starty = j;
        mat[i][j] = 0;
      } else if (c == 'O') {
        stopx = i, stopy = j;
        mat[i][j] = 0;
      } else if (c == '*') {
        mat[i][j] = -1;
      } else if (c == 'D') {
        mat[i][j] = 1;
        cords.push({i, j});
        count++;
      }
    }
  }

  return 0;
}
