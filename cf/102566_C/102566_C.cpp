#include <bits/stdc++.h>

const int mxn = 1e5 + 2;

int n, poz, nr, lung, i;
int v[mxn], best[mxn], lg[mxn], p[mxn];

inline int cautare(int x) {
  int lb = 0, rb = nr;
  while (lb <= rb) {
    int mb = (lb + rb) / 2;
    if (v[lg[mb]] < x && v[lg[mb + 1]] >= x) {
      return mb;
    } else if (v[lg[mb + 1]] < x) {
      lb = mb + 1;
    } else {
      rb = mb - 1;
    }
  }

  return nr;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  while (T--) {
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
      std::cin >> v[i];
    }

    best[1] = lg[1] = 1, lg[0] = 0, nr = 1;
    for (i = 2; i <= n; ++i) {
      poz = cautare(v[i]);
      p[i] = lg[poz];
      best[i] = poz + 1;
      lg[poz + 1] = i;

      nr = std::min(nr, poz + 1);
    }

    lung = poz = 0;
    for (i = 1; i <= n; ++i) {
      if (lung < best[i]) {
        lung = best[i], poz = i;
      }
    }

    std::cout << lung << '\n';
  }
  return 0;
}
