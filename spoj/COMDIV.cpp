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

int main() {
  std::ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    int x, y, ans(0);
    cin >> x >> y;
    int gcd = std::__gcd(x, y);
    for (int j = 1; j <= sqrt(gcd); ++j) {
      if (gcd % j == 0) {
        ans += 2;
        if (j == gcd / j) ans--;
      }
    }
    std::cout << ans << '\n';
  }
  return 0;
}
