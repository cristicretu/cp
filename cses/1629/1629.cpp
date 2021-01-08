#include <bits/stdc++.h>

typedef long long ll;
const int mxn = 2e5;
std::array<int, 2> a[mxn];

int main() {
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) std::cin >> a[i][1] >> a[i][0];
  std::sort(a, a + n);
  int ans = 0, last = 0;
  for (int i = 0; i < n; ++i)
    if (a[i][1] >= last) {
      ++ans;
      last = a[i][0];
    }
  std::cout << ans;
  return 0;
}
