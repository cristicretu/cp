#include <bits/stdc++.h>

std::ifstream fin("crescator.in");
std::ofstream fout("crescator.out");

const int mxn = 1e5 + 10;

int n, v[mxn], currl, maxl;

int main() {
  int last;
  fin >> n >> last;
  for (int i = 2; i <= n; ++i) {
    int a;
    fin >> a;
    v[i - 1] = (last < a);
    last = a;
  }

  long long ans = n;
  for (int i = 1; i <= n; ++i) {
    if (v[i] == 1)
      currl++;
    else {
      maxl = std::max(currl, maxl);
      ans += 1LL * currl * (currl + 1) / 2;
      currl = 0;
    }
  }
  maxl++;
  fout << ans << ' ' << maxl << '\n';
  return 0;
}
