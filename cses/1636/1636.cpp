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

const int INF = 1e9, mxn = 1e6 + 1, M = 1e9 + 7;

long long dp[mxn];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cout.tie(nullptr);

  int n, sum;
  cin >> n >> sum;
  std::vector<int> coins(n);
  for (auto& i : coins) cin >> i;

  dp[0] = 1;
  for (int i = 0; i < n; ++i)
    for (int j = 1; j <= sum; ++j)
      if (coins[i] <= j) dp[j] += dp[j - coins[i]], dp[j] %= M;

  std::cout << dp[sum];
  return 0;
}
