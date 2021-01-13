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

#define mat std::vector<std::vector<int>>

mat cn(int n, int m) {
  return std::vector<std::vector<int>>(n, std::vector<int>(m));
}

mat mult(mat& a, mat& b) {
  mat c = cn(a.size(), b[0].size());
  for (unsigned i = 0; i < a.size(); ++i)
    for (unsigned k = 0; k < b.size(); ++k)
      for (unsigned j = 0; j < b[0].size(); ++j) {
        c[i][j] += a[i][k] * b[k][j];
      }
  return c;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  mat r = {{0, 1}};
  mat b = {{0, 1}, {1, 1}};
  while (n) {
    if (n & 1) r = mult(r, b);
    b = mult(b, b);
    n /= 2;
  }
  std::cout << r[0][0];
  return 0;
}
