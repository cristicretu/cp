#include <stdio.h>
#include <stdlib.h>

int myabs(int a) {
  if (a < 0) a *= -1;
  return a;
}

int distanta(int la, int lb, int ca, int cb) {
  return (myabs(la - lb) + myabs(ca - cb));
}

int main() {
  FILE *fin, *fout;
  fin = fopen("rascoala.in", "r");
  fout = fopen("rascoala.out", "w");

  // int x;
  // fscanf(fin, "%d", &x);
  // fclose(fin);
  // fprintf(fout, "%d", myabs(x));
  // fclose(fout);

  int p, n, m, k, i, j;

  int a[501][501];

  fscanf(fin, "%d%d%d%d", &p, &n, &m, &k);

  for (i = 1; i <= n; ++i) {
    for (j = 1; j <= m; ++j) {
      fscanf(fin, "%d", &a[i][j]);
    }
  }

  // fprintf(fout, "%d%d%d%d", p, n, m, k);

  return 0;
}
