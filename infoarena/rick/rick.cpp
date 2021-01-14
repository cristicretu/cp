#include <bits/stdc++.h>

typedef long long ll;

std::ifstream fin("rick.in");
std::ofstream fout("rick.out");

const int mxn = 5e5 + 1, M = 1e9 + 7;

ll n, ans[mxn], rem, mx, c[mxn], mp[mxn];

int main() {
  fin >> n;
  for (int i = 0; i < n; ++i) {
    ll x;
    fin >> x;
    mp[x]++;
    mx = std::max(mx, x);
  }

  c[0] = 1;
  for (int i = 1; i <= n; ++i) c[i] = (c[i - 1] * 2) % M;

  for (int i = mx; i >= 1; --i) {
    ll x = 0, nr = 1;
    for (int j = i; j <= mx; j += i) {
      x += mp[j];
      nr = (nr + ans[j]) % M;
    }
    ans[i] = (c[x] - nr + M) % M;
    rem = (rem + ans[i] * i) % M;
  }
  fout << rem + 1;
  return 0;
}
