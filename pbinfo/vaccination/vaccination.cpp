#include <bits/stdc++.h>

int a[1001][1001], b[1001][1001];

int calc(int i, int j) {
  int sum = 0;
  sum += a[i][j] + a[i - 1][j] + a[i + 1][j] + a[i][j - 1] + a[i][j + 1];
  return sum;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  using namespace std;
  int n, m;
  cin >> n >> m;
  long long ans = 0;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      b[i][j] = calc(i, j);
    }
  }

  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= m; ++j) {
  //     cout << b[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }

  long long max = 0, x, y;
  for (int i = 2; i < n; ++i) {
    for (int j = 2; j < m; ++j) {
      if (b[i][j] > max) {
        max = b[i][j];
        x = i, y = j;
      }
    }
  }

  cout << x << ' ' << y;

  // int x, y;
  // for (int i = 2; i < n; ++i) {
  //   for (int j = 2; j < m; ++j) {
  //     if (calc(i, j) > ans) {
  //       ans = calc(i, j);
  //       x = i, y = j;
  //     }
  //   }
  // }

  // cout << x << ' ' << y;
  return 0;
}
