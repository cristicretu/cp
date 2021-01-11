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

void solve() {
  long long n;
  cin >> n;
  std::cout << (n ^ 4294967295) << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
