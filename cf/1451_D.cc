/**
 *    author: etohirse
 *    created: 28.12.2020 10:20:06
 **/
#include <bits/stdc++.h>

typedef long long ll;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    ll d, k, x(0), y(0);
    std::cin >> d >> k;
    while (1) {
      if (x <= y && (x + k) * (x + k) + y * y <= d * d)
        x += k;
      else if (x > y && (y + k) * (y + k) + x * x <= d * d)
        y += k;
      else
        break;
    }
    std::string ans = (x == y) ? "Utkarsh\n" : "Ashish\n";
    std::cout << ans;
  }
  return 0;
}
