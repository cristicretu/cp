#include <bits/stdc++.h>

std::ifstream fin("rucsac.in");
std::ofstream fout("rucsac.out");

const int mxn = 5e3 + 2;

int n, g, w[mxn], p[mxn], ans[10005];

int main() {
  fin >> n >> g;
  for (int i = 1; i <= n; ++i) fin >> w[i] >> p[i];
  for (int i = 1; i <= n; i++) {
    for (int j = g - w[i]; j >= 0; j--) {
      if (ans[j] != 0 || j == 0)
        ans[j + w[i]] = std::max(ans[j + w[i]], ans[j] + p[i]);
    }
  }
  int rem = -1;
  for (int i = 1; i <= g; ++i) rem = std::max(rem, ans[i]);
  fout << rem;
  return 0;
}
