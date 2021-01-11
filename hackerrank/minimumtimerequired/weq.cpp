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
int main() {
  std::ios_base::sync_with_stdio(false);

  ll n, goal;
  cin >> n >> goal;
  std::vector<ll> v(n);
  for (auto& i : v) cin >> i;
  std::sort(v.begin(), v.end());
  ll rb = v[n - 1] * goal, lb = 0, ans = -1;
  while (lb < rb) {
    ll mb = (lb + rb) / 2, step = 0;
    for (auto i : v) step += mb / i;
    if (step < goal) {
      lb = mb + 1;
    } else {
      ans = mb;
      rb = mb;
    }
  }
  std::cout << ans;
  return 0;
}
