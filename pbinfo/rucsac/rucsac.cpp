#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 1000;

int n, gmax;

struct obiect {
  int w, p;
} a[maxn + 1];

bool cmp(obiect a, obiect b) { return a.p * b.w > a.w * b.p; }

int main(void) {
  cin >> n >> gmax;

  for (int i = 0; i < n; ++i) {
    cin >> a[i].w >> a[i].p;
  }

  sort(a, a + n, cmp);

  double ans = 0;
  int g = 0;

  for (int i = 0; i < n; ++i) {
    if (g + a[i].w <= gmax) {
      g += a[i].w;
      ans += a[i].p;
    } else if (gmax - g > 0) {
      double factor = 1.0 * (gmax - g) / a[i].w;
      g = gmax;
      ans += a[i].p * factor;
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << a[i].w << ' ' << a[i].p << '\n';
  }

  cout << ans << '\n';
  return 0;
}
