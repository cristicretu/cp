#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

ifstream fin("rucsac.in");
ofstream fout("rucsac.out");

static const int mxn = 5e4;

int n, G;
int w[mxn + 1], p[mxn + 1], dp[mxn + 1];

void read();
void solve();

int main() {
  read();
  solve();
  return 0;
}

void solve() {
  int ans = 0;

  for (int i = 1; i <= n; ++i) {
    for (int j = G - w[i]; j >= 0; --j) {
      if (dp[j + w[i]] < dp[j] + p[i]) {
        dp[j + w[i]] = dp[j] + p[i];
        ans = max(dp[j + w[i]], ans);
      }
    }
  }

  fout << ans << '\n';
}

void read() {
  fin >> n >> G;

  for (int i = 1; i <= n; ++i) {
    fin >> w[i] >> p[i];
  }
}
