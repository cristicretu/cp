#include <bits/stdc++.h>

std::ifstream fin("transport.in");
std::ofstream fout("transport.out");

const int mxn = 16e3 + 2;

int n, k, v[mxn];

inline bool ok(int mb) {
  int sum(0), count(0);
  for (int i = 1; i <= n; i++) {
    if (sum + v[i] <= mb)
      sum += v[i];
    else {
      count++;
      sum = v[i];
    }
  }
  if (sum) count++;
  if (count <= k) return 1;
  return 0;
}

int main() {
  fin >> n >> k;
  int mx = 0, rb = 0;
  for (int i = 1; i <= n; ++i) {
    fin >> v[i];
    rb += v[i];
    mx = std::max(mx, v[i]);
  }

  int lb = mx, ans = 0;
  while (lb <= rb) {
    int mb = lb + (rb - lb) / 2;

    if (ok(mb)) {
      rb = mb - 1, ans = mb;
    } else {
      lb = mb + 1;
    }
  }
  fout << ans;
  return 0;
}
