#include <bits/stdc++.h>

std::ifstream fin("scara2.in");
std::ofstream fout("scara2.out");

int h, n, m, p, v[9], ans[9];
double dp[9], efmn = 1 << 30;

void efortminim() {
  int j = 0, suma = v[1];
  dp[1] = v[1];

  for (int i = 2; i <= n; ++i) {
    suma += v[i];

    while (suma > m) suma -= v[++j];

    double Cost = (double)suma / (i - j) + p;

    dp[i] = std::min(dp[i - 1] + v[i], dp[j] + Cost);
  }

  if (dp[n] < efmn) {
    efmn = dp[n];
    for (int i = 1; i <= n; ++i) {
      ans[i] = v[i];
    }
  }
}

void bkt(int k, int suma) {
  if (k <= n) {
    for (int i = v[k - 1] + 1; i <= m && suma + i <= h; i++) {
      v[k] = i, bkt(k + 1, suma + i);
    }
  } else {
    // return;
    if (suma == h) {
      do {
        efortminim();
      } while (std::next_permutation(v + 2, v + n + 1));
    }
  }
}

int main() {
  fin >> h >> n >> m >> p;
  bkt(1, 0);

  fout << std::setprecision(2) << std::fixed << efmn << '\n';
  for (int i = 1; i <= n; ++i) {
    fout << ans[i] << ' ';
  }
  // for (int i = 1; i <= n; ++i) {
  // fout << v[i] << ' ';
  // }

  return 0;
}
