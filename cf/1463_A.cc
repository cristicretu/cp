/**
 *    author: etohirse
 *    created: 28.12.2020 08:39:11
 **/
#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int q;
  std::cin >> q;
  while (q--) {
    int a, b, c;
    std::cin >> a >> b >> c;
    //  1 1 1 (2 + 7 = 9 %)
    std::string ans = ((std::min(a, std::min(b, c)) >= (a + b + c) / 9) &&
                       ((a + b + c) % 9 == 0))
                          ? "YES"
                          : "NO";
    std::cout << ans << '\n';
  }
  return 0;
}