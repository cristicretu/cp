#include <bits/stdc++.h>

void solve(int k, int n) { std::cout << k % n + 1 << '\n'; }

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  using namespace std;

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;

    k--;
    if (n % 2 == 0) {
      solve(k, n);
      continue;
    }
    solve(k + k / ((n - 1) / 2), n);
    continue;
  }
  return 0;
}
