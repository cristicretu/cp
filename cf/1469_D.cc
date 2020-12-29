#include <bits/stdc++.h>
void place(int n, std::vector<std::pair<int, int>> &rem) {
  if (n == 2) return;
  int nr = std::max(1, (int)sqrt(n) - 1);
  while (nr < (n + nr - 1) / nr) nr++;
  for (int i = nr + 1; i < n; ++i) rem.emplace_back(i, n);
  rem.emplace_back(n, nr);
  rem.emplace_back(n, nr);

  place(nr, rem);
}
int main() {
  using namespace std;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> rem;
    place(n, rem);
    cout << rem.size() << '\n';
    for (auto i : rem) cout << i.first << ' ' << i.second << '\n';
  }
  return 0;
}
