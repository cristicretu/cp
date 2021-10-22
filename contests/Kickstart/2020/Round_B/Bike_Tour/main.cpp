#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> v(n);
  for (int &i : v) {
    std::cin >> i;
  }

  int ans = 0;
  for (int i = 1; i < n - 1; ++i) {
    if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
      ans++;
    }
  }

  std::cout << ans;
}

int main() {
  using namespace std;

  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    solve();
    cout << '\n';
  }

  return 0;
}