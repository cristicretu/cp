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

const int mxn = 1e6 + 1;
int dp[mxn];

int main() {
  std::ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    dp[i] = 1e9;
    int i2 = i;
    while (i2) {
      dp[i] = std::min(dp[i], dp[i - i2 % 10] + 1);
      i2 /= 10;
    }
  }
  std::cout << dp[n];
  return 0;
}
