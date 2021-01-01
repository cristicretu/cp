#include <bits/stdc++.h>

void solve() {
  int n, m, a, b;
  std::cin >> n >> m >> a >> b;
  int fc = abs(b - a) - 1;
  std::vector<int> av;
  for (auto &i : av) std::cin >> i;
  std::sort(av.begin(), av.end());
  av.resize(fc);
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