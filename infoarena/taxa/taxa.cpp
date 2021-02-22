#include <fstream>
#include <queue>

std::ifstream fin("taxa.in");
std::ofstream fout("taxa.out");

static const int dx[] = {0, -1, 0, 1, 0, 1, 1, -1, -1}, oo = 1e9,
                 dy[] = {0, 0, 1, 0, -1, 1, -1, 1, -1}, mxn = 1e3 + 1;

std::queue<std::pair<int, int>> cords;

int n, m, l0, c0, lf, cf, a[mxn][mxn], mat[mxn][mxn];

inline bool ok(int i, int j) { return i && j && i <= n && j <= m; }

inline int Cost(int x, int y) { return x * y * (x != y); }

inline void Lee() {
  cords.push({l0, c0});
  mat[l0][c0] = 0;

  while (!cords.empty()) {
    int i = cords.front().first, j = cords.front().second;
    cords.pop();

    for (int k = 1; k <= 8; ++k) {
      int ni = i + dx[k], nj = j + dy[k];
      if (ok(ni, nj) && mat[ni][nj] > mat[i][j] + Cost(a[i][j], a[ni][nj]) &&
          mat[lf][cf] > mat[i][j] + Cost(a[i][j], a[ni][nj])) {
        mat[ni][nj] = mat[i][j] + Cost(a[i][j], a[ni][nj]);
        cords.push({ni, nj});
      }
    }
  }
}

int main() {
  fin >> n >> m >> l0 >> c0 >> lf >> cf;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      fin >> a[i][j];
      mat[i][j] = oo;
    }
  }

  Lee();

  fout << mat[lf][cf];
  // for (int i = 1; i <= n; ++i, fout << std::endl) {
  //   for (int j = 1; j <= m; ++j) {
  //     fout << mat[i][j] << ' ';
  //   }
  // }
  return 0;
}
