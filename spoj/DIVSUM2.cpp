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

long long int mulmod(long long int a, long long int b) {
  long long int res = 0;
  while (a > 0) {
    if (a & 1) {
      res += b;
    }
    a >>= 1;
    b <<= 1;
  }
  return res;
}

const int N = 10000000;
int lp[N + 1];
std::vector<int> pr;

int main() {
  std::ios_base::sync_with_stdio(false);

  for (int i = 2; i <= N; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
      lp[i * pr[j]] = pr[j];
  }

  int T;
  cin >> T;
  for (int q = 0; q < T; ++q) {
    ll n;
    cin >> n;
    ll ans = 1, temp = n;
    for (ll d = 2; d * d <= n; ++d) {
      ll power = d;
      while (n % d == 0) {
        power = mulmod(power, d);
        n /= d;
      }
      ans = mulmod(ans, (power - 1) / (d - 1));
    }
    if (n > 1) ans = mulmod(ans, (n * n - 1) / (n - 1));
    std::cout << ans - temp << '\n';
  }
  return 0;
}
