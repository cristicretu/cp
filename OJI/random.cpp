#include <algorithm>
#include <iostream>

static const int mxn = 1e5;

int n, a[1 + mxn];

void solve(int lb, int rb) {
  int i = lb, j = rb, piv = a[lb];

  while (i <= j) {
    while (i < rb && a[i] < piv) i++;
    while (j > lb && a[j] > piv) j--;

    if (i <= j) {
      std::swap(a[i], a[j]);
      i++;
      j--;
    }
  }

  if (lb < j) solve(lb, j);
  if (rb > i) solve(i, rb);
}

int main() {
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }

  solve(1, n);

  for (int i = 1; i <= n; ++i) {
    std::cout << a[i] << ' ';
  }

  return 0;
}