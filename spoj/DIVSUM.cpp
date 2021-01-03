#include <bits/stdc++.h>

typedef long long ll;

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

const int mxn = 1e8;
std::bitset<mxn> sieve;
int main() {
  std::ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int q = 0; q < T; ++q) {
    ll n;
    cin >> n;
    ll ans = 1, temp = n;
    for (ll d = 2; d * d <= n; ++d) {
      ll power = d;
      while (n % d == 0) {
        power *= d;
        n /= d;
      }
      ans = (1LL * ans * (power - 1) / (d - 1));
    }
    if (n > 1) ans = (1LL * ans * (n * n - 1) / (n - 1));
    std::cout << ans - temp << '\n';
  }
  return 0;
}
