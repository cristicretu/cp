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

typedef long long ll;

int n;
ll weights[20];

ll solve(int i, ll s1, ll s2) {
  if (i == n) {
    return abs(s1 - s2);
  }
  return std::min(solve(i + 1, s1 + weights[i], s2),
                  solve(i + 1, s1, s2 + weights[i]));
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> weights[i];
  }
  std::cout << solve(0, 0, 0) << "\n";
}
