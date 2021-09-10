#include <bits/stdc++.h>

std::ifstream fin("distante.in");
std::ofstream fout("distante.out");

const int mxn = 1e5 + 5, oo = (1 << 30);

struct muchie{
  int first, second, cost;
}a[mxn];

int n, m, k, i, d[50005];

int main() {
  int T;
  fin >> T;
  while (T--){
    fin >> n >> m >> k;

    for (i = 1; i <= n; ++i){
      fin >> d[i];
    }
    for (i = 1; i <= m; ++i){
      fin >> a[i].first >> a[i].second >> a[i].cost;
    }
    bool ok = 1;
    if (d[k]) ok = 0;

    for (i = 1; i <= m && ok; ++i){
      int x = a[i].first, y = a[i].second, c = a[i].cost;
      if (d[x] <= d[y] && d[x] + c < d[y]) ok = 0;
      if (d[y] < d[x] && d[y] + c < d[x]) ok = 0;
    }

    fout << (ok ? "DA\n" : "NU\n");
  }
  return 0;
}
