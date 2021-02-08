#include <bits/stdc++.h>

std::ifstream fin("pericol.in");
std::ofstream fout("pericol.out");

int main() {
  int n;
  fin >> n;
  std::vector<int> v(n);
  for (int& i : v) fin >> i;
  int m = *max_element(v.begin(), v.end()) + 1;
  std::vector<int> f(m), prim(m);
  std::vector<bool> elem(m, 1);
  std::vector<int64_t> coef(m), ans(m);
  for (int i : v) {
    f[i]++;
  }
  prim[1] = 2;
  for (int i = 1; i < m; ++i) {
    if (prim[i] == 0) {
      for (int j = i; j < m; j += i) ++prim[j];
      if (1LL * i * i < m)
        for (int j = i * i; j < m; j += i * i) elem[j] = false;
    }

    if (elem[i]) {
      int t = 1;
      if (prim[i] & 1) t = -1;
      for (int j = i, cnt = 1; j < m; j += i, ++cnt) coef[j] += t * cnt;
    }
    int_fast64_t freq = 0;
    for (int j = i; j < m; j += i) freq += f[j];
    for (int j = i; j < m; j += i) ans[j] += coef[i] * freq;
  }

  for (auto i : v) fout << ans[i] - i << ' ';
  return 0;
}
