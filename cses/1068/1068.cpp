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
  unsigned long long n;
  cin >> n;
  std::cout << n << ' ';
  while (n != 1) {
    if (n & 1)
      n = n * 3 + 1;
    else
      n /= 2;
    std::cout << n << ' ';
  }
  return 0;
}
