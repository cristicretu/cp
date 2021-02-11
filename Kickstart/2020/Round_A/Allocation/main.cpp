#include <bits/stdc++.h>

int solve() {
  int n, buget;
  std::cin >> n >> buget;
  std::vector<int> v(n);
  for (int &i : v) {
    std::cin >> i;
  }
  std::sort(v.begin(), v.end());
  long long ans = 0;
  for (int i = 0; i < n && buget > 0; ++i) {
    if (buget >= v[i]) {
      buget -= v[i];
      ans++;
    } else {
      break;
    }
  }

  return ans;
}

int main() {
  using namespace std;

  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": " << solve() << '\n';
  }

  return 0;
}