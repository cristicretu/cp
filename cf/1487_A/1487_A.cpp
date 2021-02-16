#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  using namespace std;

  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& i : v) cin >> i;
    sort(v.begin(), v.end());

    int ans = 0;
    for (int i : v) {
      if (i != v[0]) ans++;
    }

    cout << ans << '\n';
  }
  return 0;
}
