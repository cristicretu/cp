#include <bits/stdc++.h>

typedef long long ll;

const int mxn = 2100, M = 1e9;

std::string dir = "NSEW";
const int dx[4] = {0, 0, 1, -1}, dy[4] = {-1, 1, 0, 0};

std::pair<ll, ll> dp[mxn][mxn];

std::string s;

void solve(int a, int b) {
  ll xres = 0, yres = 0;
  for (int i = a; i <= b; ++i) {
    if (s[i] >= '2' && s[i] <= '9') {
      int times = 1, next = i + 2;
      while (times) {
        if (s[next] == '(')
          times++;
        else if (s[next] == ')')
          times--;
        next++;
      }
      int nv = s[i] - '0';
      solve(i + 2, next - 2);
      std::pair<ll, ll> pv = dp[i + 2][next - 2];

      pv.first *= nv, pv.second *= nv;
      xres = (xres + pv.first) % M;
      yres = (yres + pv.second) % M;
      i = next - 1;
      continue;
    }
    for (int k = 0; k < 4; ++k) {
      if (dir[k] == s[i]) {
        xres = (xres + M + dx[k]) % M;
        yres = (yres + M + dy[k]) % M;
      }
    }
  }

  dp[a][b] = std::make_pair(xres, yres);
}

void solve() {
  std::cin >> s;
  int n = s.length();

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      dp[i][j] = std::make_pair(-1, -1);
    }
  }

  solve(0, n - 1);
  ll x = dp[0][n - 1].first % M + 1;
  ll y = dp[0][n - 1].second % M + 1;
  std::cout << x << ' ' << y;
}

int main() {
  using namespace std;

  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    solve();
    cout << '\n';
  }

  return 0;
}