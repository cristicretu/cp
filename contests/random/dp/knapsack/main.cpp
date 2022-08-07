#include <iostream>
using namespace std;

const int maxn = 100 + 1, maxt = 1e4 + 1;

int a[maxt];
int dp[maxn][maxt];

int n, T;

int main() {
  cin >> n >> T;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= T; ++j) {
      if (dp[i][j] == 1) {
        dp[i + 1][j] = 1; // don't take this element
                          
        if (j + a[i] <= T) { // don't go out of bounds
          dp[i + 1][j + a[i]] = 1; // take this element
        }
      }
    }
  }

  for (int i = 0; i < n; ++i, cout << '\n') {
    for (int j = 0; j <= T; ++j) {
      cout << dp[i][j] << ' ';
    }
  }

  cout << dp[n][T];
}
