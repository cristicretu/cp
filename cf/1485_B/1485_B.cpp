#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  using namespace std;

  int n, q, k;
  cin >> n >> q >> k;
  const int mxN = 1e5 + 1;

  int a[mxN];
  for (int i = 0; i < n; ++i) cin >> a[i];

  while (q--) {
    int lb, rb;
    cin >> lb >> rb;
    lb--, rb--;

    int dist = rb - lb + 1;
    int left = a[lb] - 1 + k - a[rb];
    int right = k - dist - left;
    cout << left + right * 2 << '\n';
  }
  return 0;
}
