#include <bits/stdc++.h>

int main() {
  using namespace std;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    vector<int> av(4);
    for (auto &i : av) cin >> i;
    sort(av.begin(), av.end());
    cout << av[0] * av[2] << '\n';
  }
  return 0;
}