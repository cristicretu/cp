#include <stdio.h>

int solve(int n, long long k, int cnt[], int m[]) {}

int main() {
  FILE *fin = fopen("cadouri.in", "r"), *fout = fopen("cadouri.out", "w");
  int n;        /// first parameter for solve()
  long long k;  /// second parameter for solve()
  fscanf(fin, "%d%lld", &n, &k);
  int *cnt = new int[n], *m = new int[n];  /// last parameters for solve()
  int i;
  for (i = 0; i < n; i++) {
    fscanf(fin, "%d%d", &cnt[i], &m[i]);
  }

  fprintf(fout, "%d\n", solve(n, k, cnt, m));

  delete[] cnt;
  delete[] m;
  fclose(fin);
  fclose(fout);
  return 0;
}
