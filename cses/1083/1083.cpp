/**
 *    author: etohirse
 *    created: 06.01.2021 14:54:02
 **/
#include <bits/stdc++.h>

typedef unsigned long long ll;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  ll n, s(0);
  std::cin >> n;
  for (int i = 0u; i < n - 1; ++i) {
    ll x;
    std::cin >> x;
    s += x;
  }
  std::cout << n * (n + 1) / 2 - s;
  return 0;
}
