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
  std::vector<int> v(n + 1), p(n + 1);
  for (int i = 1; i <= n; ++i) cin >> v[i];
  for (int i = 1; i <= n; ++i) {
    int j = i - 1;
    while (v[j] >= v[i]) j = p[j];
    p[i] = j;
  }
  for (int i = 1; i <= n; ++i) std::cout << p[i] << ' ';
  return 0;
}
