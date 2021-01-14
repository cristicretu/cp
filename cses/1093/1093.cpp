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

// knapsack
const int mxn = 5e2, M = 1e9 + 7;
int n;
long long dp[mxn * (mxn + 1) / 2 + 1];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin >> n;
  int s = n * (n + 1) / 2;
  if (s & 1) {
    std::cout << 0;
    return 0;
  }
  s /= 2;
  dp[0] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = i * (i + 1) / 2; j >= i; --j) dp[j] = (dp[j] + dp[j - i]) % M;
  std::cout << dp[s] * ((M + 1) / 2) % M;
  return 0;
}
