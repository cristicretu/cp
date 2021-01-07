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

  int n, nr;
  cin >> n >> nr;
  std::vector<int> v(n), ans(n);
  for (auto& i : v) cin >> i;
  for (int i = 0; i < n; ++i) {
    int newi = (i + (n - nr)) % n;
    ans[newi] = v[i];
  }
  for (auto i : ans) std::cout << i << ' ';
  return 0;
}
