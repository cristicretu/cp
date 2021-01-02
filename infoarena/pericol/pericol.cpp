#include <bits/stdc++.h>

std::ifstream fin("pericol.in");
std::ofstream fout("pericol.out");

int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}

int main() {
  int n;
  fin >> n;
  std::vector<int> v(n), ans(n);
  for (auto &i : v) fin >> i;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      if (j != i) ans[i] += gcd(v[i], v[j]);
    }
  for (auto i : ans) fout << i << ' ';
  return 0;
}