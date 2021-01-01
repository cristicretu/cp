#include <bits/stdc++.h>

int main() {
  using namespace std;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    vector<int> ans(n);
    int left(0), right(n - 1);
    for (int i = 0; i < n; ++i) {
      if (i % 2 == 0)
        ans[i] = v[left++];
      else
        ans[i] = v[right--];
    }
    for (auto i : ans) cout << i << ' ';
    cout << '\n';
  }
  return 0;
}