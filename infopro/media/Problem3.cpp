/**
 *    author: etohirse
 *    created: 16.01.2021 09:35:16
 **/
#include <bits/stdc++.h>

std::ifstream fin("media.in");
std::ofstream fout("media.out");

const int mxn = 5e4 + 2;

int v[mxn];

int main() {
  int n, m;
  fin >> n >> m;

  int ans = 0;
  for (int i = 0; i < n; ++i) fin >> v[i];
  // for (int i = 1; i <= n; ++i) ans += subsequences(v, n, i);
  // fout << geometricMean(v, n) * pow(2, m - 2);

  long long geo = v[0];
  for (int i = 1; i < n; ++i) {
    geo *= v[i];
    geo = sqrt(geo);
  }

  // fout << geo * pow(2, n - m) / 2;
  fout << (pow(geo, 1 / n) == 1 ? m : geo * pow(2, n - m) / 2);

  return 0;
}
