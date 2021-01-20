#include <bits/stdc++.h>

const int dx[8] = {-1, -1, -1, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1},
          mxn = 15e2 + 10;

int n, m, q, t, a[mxn][mxn], raspuns = 1e9;
std::pair<int, int> poz[mxn];
bool viz[mxn][mxn];

std::queue<std::pair<int, int>> cords;

inline bool inside(int i, int j) {
  return i >= 1 and j >= 1 and i <= n and j <= n and a[i][j] != '1' and
         viz[i][j] == 0;
}

void solve(int &ans, int max_time) {
  for (int i = 1; i <= m; ++i) cords.push(poz[i]);

  // in ans numeri cate sunt colorate adica vizitate
  // iti mai trebuie o variabila pentru timp

  int time = 0;
  while (!cords.empty()) {
    int i = cords.front().first, j = cords.front().second;
    viz[i][j] = 1;
    ans++;
    cords.pop();
    for (int k = 0; k < 8; ++k) {
      int ni = i + dx[k], nj = j + dy[k];
      if (inside(ni, nj)) {
        cords.push({ni, nj});
      }
    }
  }
}

bool ok(int mb) {
  memset(viz, 0, sizeof(viz));
  int ans = 0;
  solve(ans, mb);
  return ans >= t;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> n;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) std::cin >> a[i][j];

  std::cin >> m;
  for (int i = 1; i <= m; ++i) {
    int a, b;
    std::cin >> a >> b;
    poz[i].first = a, poz[i].second = b;
  }

  while (q--) {
    std::cin >> t;
    if (t > n * n)
      std::cout << "-1\n";
    else {
      int lb = 1, rb = t / 8;
      while (rb - lb > 1) {
        int mb = lb + (rb - lb) / 2;
        if (ok(mb))
          lb = mb, raspuns = std::min(raspuns, mb);
        else
          rb = mb;
      }
      std::cout << lb;
    }
  }
  return 0;
}
