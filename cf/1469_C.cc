#include <bits/stdc++.h>
typedef long long ll;
void solve() {
  int n;
  ll k;
  std::cin >> n >> k;
  std::vector<ll> h(n);
  for (auto &i : h) std::cin >> i;
  std::vector<ll> ans(n, -1);
  std::vector<std::pair<ll, int>> v;
  for (int i = 0; i < n; ++i) {
    v.emplace_back(h[i], i);
  }
  std::sort(v.begin(), v.end());
  std::reverse(v.begin(), v.end());
  for (auto i : v) {
    ll h0 = h[i.second];
    if (i.second != 0) h0 = std::max(h0, ans[i.second - 1] - k + 1);
    if (i.second != n - 1) h0 = std::max(h0, ans[i.second + 1] - k + 1);
    ans[i.second] = h0;
  }
  if (ans[0] != h[0] || ans.back() != h.back()) {
    std::cout << "NO\n";
    return;
  }
  for (int i = 0; i < n; ++i) {
    if (ans[i] > h[i] + k - 1) {
      std::cout << "NO\n";
      return;
    }
  }
  for (int i = 0; i < n - 1; ++i) {
    if (abs(ans[i] - ans[i + 1]) >= k) {
      std::cout << "NO\n";
      return;
    }
  }
  std::cout << "YES\n";
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
