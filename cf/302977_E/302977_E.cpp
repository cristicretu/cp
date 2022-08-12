#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

#define ONLINE_JUDGE

using ll = long long;
#define mod 1000000007
const ll INF = 1e17;

void solve() {
  ll n, k, p;
  cin >> n >> k >> p;

  ll a[2001];
  for (ll i = 0; i < n; ++i) {
    cin >> a[i];
  }

  ll b[2001];
  for (ll i = 0; i < k; ++i) {
    cin >> b[i];
  }

  sort(a, a + n);
  sort(b, b + k);

  ll dp[k + 1][n + 1];
  for (ll i = 0; i <= k; ++i) {
    for (ll j = 0; j <= n; ++j) {
      dp[i][j] = INF;
    }
  }

  dp[0][0] = 0;
  for (ll i = 0; i < k; ++i) {
    for (ll j = 0; j <= n; ++j) {
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);  // don't take

      if (j < n) {
        dp[i + 1][j + 1] = min(dp[i + 1][j + 1],
                               max(dp[i][j], abs(a[j] - b[i]) + abs(b[i] - p)));
      }
    }
  }

  cout << dp[k][n] << '\n';
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
