#include <fstream>
#include <iostream>
using namespace std;

#define ONLINE_JUDGE

using ll = long long;
#define mod 1000000007

void solve() {
  int n, k;
  cin >> n >> k;
  int a[n], b[n];

  for (ll i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (ll i = 0; i < n; ++i) {
    cin >> b[i];
  }

  ll p[n];
  ll r = p[0] = a[0] * b[0];
  for (ll i = 1; i < n; ++i) {
    r += a[i] * b[i];
    p[i] = r;
  }

  ll s[n];
  r = 0;
  for (ll i = n - 1; i >= 0; --i) {
    r += a[i] * b[i];
    s[i] = r;
  }

  ll pref[n];
  r = 0;
  for (int i = 0; i < n; ++i) {
    r += a[i];
    pref[i] = r;
  }

  ll ans = 0;
  for (int i = 0; i + k - 1 < n; ++i) {
    ll curr = 0;
    if (i > 0) curr += p[i - 1];
    if (i + k < n) curr += s[i + k];

    ll range_sum = pref[i + k - 1];
    if (i > 0) range_sum -= pref[i - 1];
    curr += range_sum;
    ans = max(ans, curr);
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  ll test = 1;
  // cin>>test;

  while (test--) {
    solve();
  }

  return 0;
}
