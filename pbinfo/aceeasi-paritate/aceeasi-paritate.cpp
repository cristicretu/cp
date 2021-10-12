#include <iostream>
#include <vector>

int medie(int a, int b) { return (a + b) / 2; }

int main() {
  int i;
  int n;
  scanf("%d", &n);

  std::vector<int> v;

  int x;
  scanf("%d", &x);
  v.push_back(x);

  for (int i = 1; i < n; ++i) {
    int a;
    scanf("%d", &a);

    if (a % 2 == x % 2) {
      v.push_back(medie(x, a));
    }

    v.push_back(a);
    x = a;
  }

  for (auto j : v) {
    printf("%d ", j);
  }
  return 0;
}
