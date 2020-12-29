#include <bits/stdc++.h>

int solve(std::vector<int> &av) {
  int rem(0), ans(0);
  for (auto i : av) rem += i, ans = std::max(ans, rem);
  return ans;
}

int main() {
  using namespace std;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n;
    vector<int> r(n);
    for (auto &i : r) cin >> i;
    cin >> m;
    vector<int> b(m);
    for (auto &i : b) cin >> i;
    cout << solve(r) + solve(b) << '\n';
  }
  return 0;
}