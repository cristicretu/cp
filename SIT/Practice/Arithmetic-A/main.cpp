#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--) {
    int a, b, c;
    std::cin >> a >> b >> c;

    if (a * b == c) {
      std::cout << "Yes\n" << a << ' ' << b << ' ' << c << '\n';
    } else if (b * c == a) {
      std::cout << "Yes\n" << b << ' ' << c << ' ' << a << '\n';
    } else if (a * c == b) {
      std::cout << "Yes\n" << a << ' ' << c << ' ' << b << '\n';
    } else {
      std::cout << "No\n";
    }
  }
}