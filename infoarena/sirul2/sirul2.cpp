#include <fstream>
#include <iostream>

std::fstream fin("sirul2.in", std::ios::in);
std::fstream fout("sirul2.out", std::ios::out);

static const int M = 20173333, mxn = 1e5;

int p, n, k;

long long power(int x, int n) {
  if (n == 0) return 1;
  if (n == 1) return x % M;

  long long y = power(x, n / 2);
  y = (y * y) % M;

  if (n & 1) y = y * x % M;
  return y;
}

long long comb(int n, int k) {
  long long up = 1, down = 1;
  for (int i = 1; i <= n; ++i) {
    up = (up * i) % M;

    if (i <= k) {
      down = (down * i) % M;
    }
    if (i <= (n - k)) {
      down = (down * i) % M;
    }
  }

  down = power(down, M - 2) % M;
  return (down * up) % M;
}

int main() {
  fin >> p >> n >> k;

  if (p == 1) {
    fout << comb(n - 1, k - 1) << '\n';
  } else {
    int v[1 + mxn];

    v[0] = v[1] = 1;
    for (int i = 2; i <= n; ++i) {
      v[i] = (2 * v[i - 1]) % M;

      if (i >= k) {
        v[i] = (v[i] - v[i - k - 1] + M) % M;
      }
    }
    fout << v[n] << '\n';
  }
  return 0;
}
