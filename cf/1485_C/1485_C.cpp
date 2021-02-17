#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  using namespace std;

  int t;
  cin >> t;
  while (t--) {
    int64_t x, y;
    cin >> x >> y;
    int64_t b = 2, ans = 0;
    while (b <= y + 1 && x / b > 0) {
      if (b - 2 < x / b) {
        ans += b - 2;
        b++;
        continue;
      }

      int64_t b_end = min(x / (x / b), y + 1);
      ans += (b_end - b + 1) * (x / b);
      b = b_end + 1;
    }

    cout << ans << '\n';
  }
  return 0;
}
