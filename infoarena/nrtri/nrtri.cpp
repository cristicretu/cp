#include <bits/stdc++.h>

std::ifstream fin("nrtri.in");
std::ofstream fout("nrtri.out");

const int mxn = 8e2 + 2;

int n, v[mxn];

int main() {
  fin >> n;
  for (int i = 1; i <= n; ++i) fin >> v[i];

  std::sort(v + 1, v + n + 1);

  int ans = 0;
  for (int i = 1; i <= n - 2; ++i) {
    for (int j = i + 1; j <= n - 1; ++j) {
      int lb = j + 1, rb = n;

      while (lb <= rb) {
        int mb = lb + (rb - lb) / 2;

        if (v[i] + v[j] >= v[mb])
          lb = mb + 1;
        else
          rb = mb - 1;
      }
      ans += rb - j;
    }
  }
  fout << ans;
  return 0;
}
