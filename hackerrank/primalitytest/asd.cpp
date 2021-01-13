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

bool prime(long long n) {
  if (n == 0 || n == 1) return false;
  if (n == 2 || n == 3) return true;
  if (n % 2 == 0) return false;
  for (int d = 3; d * d <= n; d += 2) {
    if (n % d == 0) return false;
  }
  return true;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    std::cout << (prime(n) == 0 ? "Not prime\n" : "Prime\n");
  }

  return 0;
}
