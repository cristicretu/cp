#include <bits/stdc++.h>

std::ifstream fin("amedie.in");
std::ofstream fout("amedie.out");

int n, m, q, a[810][810], fr[100010];

int main() {
  fin >> n >> m >> q;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      fin >> a[i][j];
      fr[a[i][j]]++;
    }
  int boi = n * m;
  while (q--) {
    char c;
    fin >> c;
    if (c == 'L') {
      int x;
      fin >> x;
      for (int i = 1; i <= m; ++i) {
        if (!a[x][i]) continue;
        boi--, fr[a[x][i]]--;
      }
    } else if (c == 'C') {
      int x;
      fin >> x;
      for (int i = 1; i <= n; ++i) {
        if (!fr[a[i][x]]) continue;
        boi--, fr[a[i][x]]--;
      }
    } else {
      int num = 0;
      for (int i = 1; i <= 100010; ++i) {
        num += fr[i];
        if (num >= (boi / 2 + boi % 2)) {
          fout << i << '\n';
          break;
        }
      }
    }
  }
  return 0;
}
