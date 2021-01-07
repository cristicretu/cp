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

const int INF = 1e9, mxn = 1e6 + 1;

long long dp[mxn];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cout.tie(nullptr);

  int n, sum;
  cin >> n >> sum;
  std::vector<int> coins(n);
  for (auto& i : coins) cin >> i;

  dp[0] = 0;
  for (int i = 1; i <= sum; ++i) {
    dp[i] = INF;
    for (auto c : coins) {
      if (i >= c) {
        dp[i] = std::min(dp[i], dp[i - c] + 1);
      }
    }
  }

  std::cout << (dp[sum] >= 1e9 ? -1 : dp[sum]);
  return 0;
}
