#include <bits/stdc++.h>

std::ifstream fin("gheizere.in");
std::ofstream fout("gheizere.out");

struct g {
  int x, y, r, t, d;
};

std::vector<g> v;
int n, m, pct, s, f, curr = 1;

bool dp[3][255][255];

int main() {
  fin >> n >> m >> pct >> s >> f;
  v.resize(pct + 1);
  for (int i = 1; i <= pct; ++i)
    fin >> v[i].x >> v[i].y >> v[i].r >> v[i].t >> v[i].d;

  dp[0][s][1] = 1;
  while (!dp[curr % 2][f][m]) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        int nc = 1 - curr % 2;
        dp[curr % 2][i][j] = dp[nc][i + 1][j] || dp[nc][i][j + 1] ||
                             dp[nc][i][j - 1] || dp[nc][i - 1][j];
      }
    }

    for (int q = 1; q <= pct; ++q) {
      if (curr % (v[q].t + v[q].d) < v[q].t) continue;
      for (int i = std::max(v[q].x - v[q].r, 1);
           i <= std::min(v[q].x + v[q].r, n); ++i) {
        for (int j = std::max(v[q].y - v[q].r, 1);
             j <= std::min(v[q].y + v[q].r, m); ++j) {
          dp[curr % 2][i][j] = 0;
        }
      }
    }
    curr++;
  }
  curr--;
  fout << curr;
  return 0;
}
