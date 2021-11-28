#include <bits/stdc++.h>

std::ifstream fin("cautbin.in");
std::ofstream fout("cautbin.out");

static const int mxn = 1e5;

int n, v[1 + mxn], m;

int main() {
  fin >> n;
  for (int i = 1; i <= n; ++i) {
    fin >> v[i];
  }
  fin >> m;
  for (int t = 1; t <= m; ++t) {
    int a, b, ans;
    fin >> a >> b;
    if (a == 2) {
      int lb = 1, rb = n;
      while (lb <= rb) {
        int mb = lb + (rb - lb) / 2;

        if (v[mb] < b) {
          lb = mb + 1;
        } else {
          rb = mb - 1;
          ans = mb;
        }
      }

      fout << ans << '\n';
    } else {
      int lb = 1, rb = n;
      while (lb <= rb) {
        int mb = lb + (rb - lb) / 2;

        if (v[mb] <= b) {
          ans = mb;
          lb = mb + 1;
        } else {
          rb = mb - 1;
        }
      }

      if (a == 0) {
        if (v[ans] == b)
          fout << ans << '\n';
        else
          fout << "-1\n";
      } else {
        fout << ans << '\n';
      }
    }
  }
  return 0;
}
