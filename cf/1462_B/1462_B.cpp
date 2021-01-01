#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;

  for (int i = 0; i <= 4; ++i)
    if (s.substr(0, i) + s.substr(n - 4 + i, 4 - i) == "2020") {
      std::cout << "YES\n";
      return;
    }
  std::cout << "NO\n";
}

int main() {
  using namespace std;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}