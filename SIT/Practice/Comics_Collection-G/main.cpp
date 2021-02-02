#include <bits/stdc++.h>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    int count5 = 0, count3 = 0, count2 = 0, count1 = 0;
    std::cin >> n;

    for (int i = 1; i <= n; ++i) {
      if (i % 5 == 0) {
        count5++;
      } else if (i % 3 == 0) {
        count3++;
      } else if (i % 2 == 0) {
        count2++;
      } else {
        count1++;
      }
    }
    std::cout << count5 << ' ' << count3 << ' ' << count2 << ' ' << count1
              << std::endl;
  }
}