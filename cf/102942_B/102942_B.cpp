#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  int par = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    if (x % 2 == 0) par++;
  }
  if (par == n) {
    std::cout << "-1\n";
    return;
  }
  std::cout << par << '\n';
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
