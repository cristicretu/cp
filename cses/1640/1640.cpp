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

  int n, sum;
  cin >> n >> sum;
  std::map<int, int> s;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (s.find(sum - a) != s.end()) {
      std::cout << s[sum - a] + 1 << ' ' << i + 1;
      return 0;
    }
    s[a] = i;
  }
  std::cout << "IMPOSSIBLE";
  return 0;
}
