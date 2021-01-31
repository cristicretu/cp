#include <bits/stdc++.h>

std::ifstream fin("flip.in");
std::ofstream fout("flip.out");

int n, m, mat[25][25], ans;

int solve() {
  int rem = 0;
  for (int i = 1; i <= n; ++i) {
    int temp = 0;
    for (int j = 1; j <= m; ++j) {
      temp += mat[i][j];
    }
    if (temp < 0) temp *= -1;
    rem += temp;
  }
  return rem;
}

void bkt(int j) {
  if (j <= m) {
    bkt(j + 1);
    for (int i = 1; i <= n; ++i) mat[i][j] *= -1;
    bkt(j + 1);
  } else {
    ans = std::max(ans, solve());
  }
}

int main() {
  fin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) fin >> mat[i][j];
  }

  bkt(1);
  fout << ans;
  return 0;
}
