#include <bits/stdc++.h>

int main() {
  using namespace std;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  unsigned long long dp[1002];
  cin >> n;
  if (!(n & 1))
    cout << (n / 2 + 1) * (n / 2 + 1);
  else
    cout << 2 * (n / 2 + 1) * (n / 2 + 2);
  return 0;
}