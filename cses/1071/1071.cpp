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

  int t;
  cin >> t;
  while (t--) {
    long long x, y;
    cin >> y >> x;
    long long z = std::max(x, y);
    if (z == 1)
      std::cout << "1\n";
    else {
      long long z2 = (z - 1) * (z - 1), ans;
      if (z % 2) {
        if (y == z)
          ans = z2 + x;
        else
          ans = z2 + 2 * z - y;
      } else {
        if (x == z)
          ans = z2 + y;
        else
          ans = z2 + 2 * z - x;
      }
      std::cout << ans << '\n';
    }
  }
  return 0;
}
