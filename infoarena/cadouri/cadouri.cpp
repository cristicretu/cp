#include <bits/stdc++.h>

typedef long long ll;

std::ifstream fin("cadouri.in");
std::ofstream fout("cadouri.out");

const int mxn = 5e6 + 10, mxf = 7e4 + 10;
ll n, k, cnt[mxn], m[mxn];
std::pair<ll, ll> fr[mxf];

int main() {
  fin >> n >> k;
  for (int i = 1; i <= n; ++i) fin >> cnt[i] >> m[i];
  for (ll i = 1; i <= n; i++) {
    ll x = ((m[i]) >> 16LL);
    fr[x].first += (ll)cnt[i];
  }
  ll cnt;
  for (ll mask = 0;; mask++) {
    if (fr[mask].first < k) {
      k -= fr[mask].first;
      continue;
    }
    cnt = mask;
    break;
  }
  for (ll i = 1; i <= n; i++) {
    ll x = ((m[i]) >> 16);
    if (x != cnt) continue;
    x = ((m[i]) & ((1LL << 16) - 1));
    fr[x].first += (ll)cnt[i];
  }
  ll cnt1;
  for (ll mask = 0;; mask++) {
    if (fr[mask].second < k) {
      k -= fr[mask].second;
      continue;
    }
    cnt1 = mask;
    break;
  }
  fout << cnt1 + (cnt << 16) << '\n';
  return 0;
}
