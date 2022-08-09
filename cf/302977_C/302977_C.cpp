#include <fstream>
#include <iostream>
using namespace std;

#define ONLINE_JUDGE

using ll = long long;
#define mod 1000000007

void solve() {
  ll n;

  cin >> n;

  const ll inf = 1e10;

  ll f[n + 1][8];

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < 8; ++j) {
      f[i][j] = inf;
    }
  }

  f[0][0] = 0;

  for (int i = 0; i < n; ++i) {
    int cost;
    string s;
    cin >> cost >> s;

    int string_mask = 0;
    for (int pos = 0; pos < 3; ++pos) {
      // c: C, B, A
      char c = 'C' - pos;
      bool have = 0;
      for (char d : s) {
        if (d == c) {
          have = 1;
          break;
        }
      }
      if (have) {
        string_mask += (1 << pos);  // 2^pos
      }
    }
    for (ll mask = 0; mask < 8; ++mask) {
      f[i + 1][mask] = min(f[i + 1][mask], f[i][mask]);
      f[i + 1][mask | string_mask] =
          min(f[i + 1][mask | string_mask], f[i][mask] + cost);
    }
  }

  ll ans = f[n][7];
  if (ans == inf) ans = -1;
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
