#include <iostream>

FILE *in = fopen("subgraf.in", "r");
FILE *out = fopen("subgraf.out", "w");

const int mxn = 100;
int n, ans;

int mat[mxn + 1][mxn + 1];

inline bool ePrim(int k) {
  if (k < 2) return false;
  if (k == 2 || k == 3) return true;
  if (k % 2 == 0) return false;

  int i;
  for (i = 2; i * i <= k; ++i) {
    if (k % i == 0) {
      return false;
    }
  }

  return true;
}

int main(void) {
  fscanf(in, "%d", &n);

  int x, y;
  while (fscanf(in, "%d%d", &x, &y) != EOF) {
    mat[x][y] = mat[y][x] = 1;
  }

  int i, j;
  for (i = 1; i <= n; ++i) {
    if (ePrim(i)) {
      for (j = 1; j <= n; ++j) {
        mat[i][j] = mat[j][i] = 0;
      }
    }
  }

  for (i = 1; i <= n; ++i) {
    for (j = i + 1; j <= n; ++j) {
      if (mat[i][j] == 1) ans += 1;
    }
  }

  fprintf(out, "%d\n", ans);
}
