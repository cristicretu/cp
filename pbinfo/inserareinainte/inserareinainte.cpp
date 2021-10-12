#include <cmath>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::vector<int> v;

  scanf("%d", &n);
  int i;
  for (i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);

    if (int(sqrt(x)) == sqrt(x)) {
      v.push_back(sqrt(x));
    }

    v.push_back(x);
  }

  for (auto j : v) {
    printf("%d ", j);
  }

  return 0;
}
