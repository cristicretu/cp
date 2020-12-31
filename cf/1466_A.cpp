#include <bits/stdc++.h>

int main() {
  using namespace std;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, ans(0);
    cin >> n;
    vector<int> av(n);
    for (auto &i : av) cin >> i;
    set<int> s;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) s.insert(av[j] - av[i]);

    cout << s.size() << '\n';
  }
  return 0;
}
