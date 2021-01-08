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
  std::vector<int> v;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    int p = upper_bound(v.begin(), v.end(), a) - v.begin();
    if (p < v.size())
      v[p] = a;
    else
      v.push_back(a);
  }
  std::cout << v.size();
  return 0;
}
