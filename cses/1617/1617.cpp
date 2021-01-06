#include <bits/stdc++.h>

const int M = 1e9 + 7;

int main() {
  std::ios_base::sync_with_stdio(false);
  long long n, s = 1;
  std::cin >> n;
  for (int i = 0; i < n; ++i) s = s * 2 % M;
  std::cout << s % M;
  return 0;
}
