#include <bits/stdc++.h>

const int mxn = 2e5;
long long a[mxn];

int main() {
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::map<int, int> mp;
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  int ans = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    while (j < n && mp[a[j]] < 1) {
      mp[a[j]]++;
      ++j;
    }
    ans = std::max(j - i, ans);
    mp[a[i]]--;
  }
  std::cout << ans;
  return 0;
}
