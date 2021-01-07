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

typedef long long ll;

const int mxn = 1e6 + 1, M = 1e9 + 7;

ll dp[mxn];

int main() {
  std::ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  dp[0] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= std::min(i, 6); ++j) dp[i] = (dp[i] + dp[i - j]) % M;
  std::cout << dp[n];
  return 0;
}
