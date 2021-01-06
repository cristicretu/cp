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
  std::vector<int> v(n);
  for (auto& i : v) cin >> i;
  long long ans(0);
  for (int i = 0; i < n; ++i) {
    if (v[i]) {
      bool ok = false;
      for (int j = i + 1; j < n; ++j)
        if (v[j] > v[i]) v[j] = 0, ok = true;
      ok = true;
      ans += (int)ok;
    }
    // for (auto j : v) std::cout << j;
    // std::cout << '\n';
  }
  std::cout << ans;
  return 0;
}
