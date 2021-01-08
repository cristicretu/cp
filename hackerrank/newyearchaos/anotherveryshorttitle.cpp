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
  int n, rem(0);
  cin >> n;
  std::vector<int> v(n);
  for (auto& i : v) cin >> i;
  for (int i = v.size() - 1; i >= 0; --i) {
    if (v[i] - (i + 1) > 2) {
      std::cout << "Too chaotic\n";
      return;
    }
    for (int j = std::max(0, v[i] - 2); j < i; ++j)
      if (v[j] > v[i]) ++rem;
  }
  std::cout << rem << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
