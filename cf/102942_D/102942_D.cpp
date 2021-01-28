#include <bits/stdc++.h>

void solve() {
  int a, b;
  std::cin >> a >> b;
  std::cout << (((a ^ b) == (a + b)) ? "No\n" : "Yes\n");
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
