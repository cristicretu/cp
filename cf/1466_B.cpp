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
    set<int> s;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      if (s.count(x)) x++;
      s.insert(x);
    }
    cout << s.size() << '\n';
  }
  return 0;
}
