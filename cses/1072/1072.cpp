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
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i, std::cout << '\n') {
    long long ok = i * i, ok1 = ok * (ok - 1) / 2;
    if (i > 2) ok1 -= (i - 1) * (i - 2) * 4;
    std::cout << ok1;
  }
  return 0;
}
