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

std::vector<ll> v;

int main() {
  std::ios_base::sync_with_stdio(false);

  ll n, q;
  cin >> n >> q;
  v.resize(n + 1);
  while (q--) {
    ll a, b, k;
    cin >> a >> b >> k;
    v[a] += k;                        // we mark the start of the changes
    if ((b + 1) <= n) v[b + 1] -= k;  // we mark the end of the changes
  }
  long long x(0), ans(0);
  for (int i = 1; i <= n; ++i) x += v[i], ans = std::max(ans, x);
  std::cout << ans;
  return 0;
}
