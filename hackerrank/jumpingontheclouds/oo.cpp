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
  // std::bitset<110> v;

  // for (int i = 0; i < n; ++i) {
  //   bool x;
  //   cin >> x;
  //   v[i] = x;
  // }

  std::vector<int> v(n);
  for (auto& i : v) cin >> i;

  int ans(0), i(0);
  while (i < n) {
    if (v[i + 2] == 0)
      ans++, i += 2;
    else if (v[i + 1] == 0)
      ans++, i += 1;
  }

  // if (n == 2)
  //   std::cout << 1;
  // else
  std::cout << ans;
  return 0;
}
