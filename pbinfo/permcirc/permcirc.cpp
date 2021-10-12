#include <iostream>
#include <vector>

int v[100];

int main() {
  int i, j, cnt;
  int n;

  std::cin >> n;
  for (i = 0; i < n; ++i) {
    std::cin >> v[i];
  }

  for (i = 0; i < n; ++i, std::cout << '\n') {
    for (j = i, cnt = 0; cnt < n; j++, cnt++) {
      // std::cerr << cnt << ',' << j << ' ' << v[j] << '\n';
      std::cout << v[j] << ' ';
      if (cnt < n && j == n - 1) {
        j = -1;
      }
    }
  }
  return 0;
}
