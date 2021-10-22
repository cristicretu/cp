#include <bits/stdc++.h>

const int mxn = 1e6 + 2;
int n, k, v[mxn];
;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    int a, b;
    std::cin >> a >> b;
    for (int i = a; i <= a + b; ++i) {
      v[i]++;
    }
  }

  for (int i = 1; i <= 6; ++i) std::cout << v[i] << ' ';
}