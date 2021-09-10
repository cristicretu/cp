#include <iostream>

int count(long n) {
  int ans = 0;
  for (int i = 0; i < 32; ++i) {
    if (n & (1 << i)) ans++;
  }

  return ans;
}

bool powerof2(int n) { return (n & (n - 1)) == 0; }

int lowl(long n) { return n ^ (n & (n - 1)); }

int main() {
  // int n;
  // std::cin >> n;
  // std::cout << count(n) << ' ' << powerof2(n) << ' ' << lowl(n) << '\n';

  long n;
  std::cin >> n;
  std::cout << (1 << n);

  return 0;
}