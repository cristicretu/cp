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
  std::unordered_set<int> s;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    s.insert(x);
  }
  std::cout << s.size();
  return 0;
}
