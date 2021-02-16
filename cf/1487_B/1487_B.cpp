#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  using namespace std;

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;

    if (n % 2 == 0) {
      cout << ((n - 1 - k) % n + n) % n + 1 << '\n';
      continue;
    }
    if (k <= n / 2) {
      cout << ((n - 1 - k) % n + n) % n + 1 << '\n';
      continue;
    }
    int cnt = 1;
    cnt += (n - 1) / 2;
    k += cnt;
    cout << ((n - 1 - k) % n + n) % n + 1 << '\n';
    continue;
  }
  return 0;
}
