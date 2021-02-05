#include <bits/stdc++.h>

typedef long long ll;

std::ifstream fin("margiki.in");
std::ofstream fout("margiki.out");

#define mat std::vector<std::vector<ll>>

const int M = 1e9 + 7;

mat cn(int n, int m) {
  return std::vector<std::vector<ll>>(n, std::vector<ll>(m));
}

mat mult(mat &a, mat &b) {
  mat c = cn(a.size(), b[0].size());
  for (unsigned i = 0; i < a.size(); ++i) {
    for (unsigned k = 0; k < b.size(); ++k) {
      for (unsigned j = 0; j < b[0].size(); ++j) {
        c[i][j] += a[i][k] + b[k][j];
        if (c[i][j] >= M) c[i][j] -= M;
      }
    }
  }

  for (unsigned i = 0; i < a.size(); ++i) {
    for (unsigned j = 0; j < b[0].size(); ++j) {
      c[i][j] %= M;
    }
  }

  return c;
}

int main() {
  ll n;
  fin >> n;
  mat r = {{1, 1}};
  mat b = {{1, 1}, {1, 1}};

  for (int i = 0; i < b.size(); ++i, fout << '\n')
    for (int j = 0; j < b.size(); ++j) fout << b[i][j] << ' ';

  // while (n) {
  //   if (n & 1) r = mult(r, b);
  //   b = mult(b, b);
  //   n >>= 1;
  // }

  // fout << r[0][0];
  return 0;
}
