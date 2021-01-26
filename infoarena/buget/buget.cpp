#include <bits/stdc++.h>

typedef unsigned long long ll;

std::ifstream fin("buget.in");
std::ofstream fout("buget.out");

const int mxn = 1e5 + 2;

int n;
ll b, p[mxn];

bool ok(ll mb) {
  ll sum = 0;
  for (int i = 1; i <= n; ++i)
    if (p[i] > mb)
      sum += mb;
    else
      sum += p[i];

  return sum <= b;
}

int main() {
  fin >> n >> b;

  for (int i = 1; i <= n; ++i) fin >> p[i];

  ll lb = 0, rb = b, ans = 0;
  while (rb - lb > 1) {
    ll mb = lb + (rb - lb) / 2;

    if (ok(mb))
      lb = mb, ans = std::max(ans, lb);
    else
      rb = mb;
  }

  fout << ans;

  return 0;
}
