#include <iostream>
using namespace std;

int n, a[101][101], ans[101][101];

int main() {
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
    }
  }

  // only go down or right, find the lowest cost path
  ans[1][1] = a[1][1];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i > 1 && j > 1) {
        ans[i][j] = a[i][j] + min(ans[i - 1][j], ans[i][j - 1]);
      } else if (i > 1) {
        ans[i][j] = a[i][j] + ans[i - 1][j];
      } else if (j > 1) {
        ans[i][j] = a[i][j] + ans[i][j - 1];
      }
    }
  }

  // for (int i = 1; i <= n; ++i, cout << '\n') {
  //  for (int j = 1; j <= n; ++j) {
  //    cout << ans[i][j] << ' ';
  //  }
  //}
  cout << ans[n][n] << '\n';
}
