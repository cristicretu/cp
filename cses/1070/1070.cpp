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
  if (n == 1) {
    std::cout << 1;
    return 0;
  } else if (n == 2 || n == 3) {
    std::cout << "NO SOLUTION";
    return 0;
  } else if (n % 2 == 0) {
    for (int i = 2; i <= n; i += 2, std::cout << ' ') std::cout << i;
    for (int i = 1; i <= n; i += 2, std::cout << ' ') std::cout << i << ' ';
    return 0;
  } else {
    for (int i = n - 1; i > 0; i -= 2, std::cout << ' ') std::cout << i;
    for (int i = n; i > 0; i -= 2, std::cout << ' ') std::cout << i;
  }
  return 0;
}
