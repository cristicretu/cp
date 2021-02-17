#include <bits/stdc++.h>

inline int s(int n) {
  int ans = 0;
  while (n) {
    ans++;
    n /= 10;
  }
  return ans;
}

int count(int a, int b) {
  if (b == 1) return INT_MAX;
  int c = 0;
  while (a != 0) {
    a /= b;
    c++;
  }

  return c;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  using namespace std;

  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;

    int best = INT_MAX;
    for (int i = 0; i < 30; ++i) {
      best = min(best, i + count(a, b + i));
    }

    cout << best << '\n';
  }
  return 0;
}
