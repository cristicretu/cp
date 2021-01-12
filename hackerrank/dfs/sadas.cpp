#include <bits/stdc++.h>

class Read {
 public:
  template <class T>
  Read& operator>>(T& number) {
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if (c == '-') {
      negative = true;
      c = getchar();
    }
    for (; (c > 47 && c < 58); c = getchar()) number = number * 10 + c - 48;
    if (negative) number *= -1;
    return *this;
  }
};
Read cin;

const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
          dy[8] = {0, 1, 1, 1, 0, -1, -1, -1}, mxn = 12;

int a[mxn][mxn], ans, count, n, m;
bool viz[mxn][mxn];

inline bool ok(int i, int j) {
  return i && j && i <= n && j <= m && a[i][j] == 1 && viz[i][j] == 0;
}

inline void dfs(int i, int j) {
  viz[i][j] = 1;
  count++;
  if (ok(i - 1, j - 1)) dfs(i - 1, j - 1);
  if (ok(i - 1, j)) dfs(i - 1, j);
  if (ok(i - 1, j + 1)) dfs(i - 1, j + 1);
  if (ok(i, j + 1)) dfs(i, j + 1);
  if (ok(i + 1, j + 1)) dfs(i + 1, j + 1);
  if (ok(i + 1, j)) dfs(i + 1, j);
  if (ok(i + 1, j - 1)) dfs(i + 1, j - 1);
  if (ok(i, j - 1)) dfs(i, j - 1);
}

int main() {
  std::ios_base::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) cin >> a[i][j];

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (a[i][j] == 1 && viz[i][j] == 0) {
        count = 0;
        dfs(i, j);
        ans = std::max(ans, count);
      }
  std::cout << ans;
  return 0;
}
