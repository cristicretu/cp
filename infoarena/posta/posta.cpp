#include <bits/stdc++.h>

std::ifstream fin("posta.in");
std::ofstream fout("posta.out");

const int mxn = 1e5 + 2;

struct per {
  int a, b, c;
} s[mxn];
int av[mxn], ans[mxn], k;

bool compare(per x, per y) {
  if (x.a == y.a) return x.b < y.b;
  return x.a < y.a;
}

int main() {
  int n;
  fin >> n;

  for (int i = 1; i <= n; ++i) {
    int x, y;
    fin >> x >> y;
    s[i].a = x + y;
    s[i].b = y - x;
    s[i].c = i;
  }

  std::sort(s + 1, s + n + 1, compare);

  for (int i = 1; i <= n; ++i) {
    int nr = 0;
    for (int step = 1 << 16; step; step >>= 1)
      if (nr + step <= k and av[nr + step] > s[i].b) nr += step;
    if (k == nr) k++;
    av[nr + 1] = s[i].b;
    ans[s[i].c] = nr + 1;
  }

  fout << k << '\n';
  for (int i = 1; i <= n; ++i) fout << ans[i] << ' ';
  return 0;
}
