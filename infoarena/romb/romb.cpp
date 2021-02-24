#include <cmath>
#include <fstream>

#define _USE_MATH_DEFINES

std::fstream fin("romb.in", std::ios::in);
std::fstream fout("romb.out", std::ios::out);

const double PI = M_PI;

using i64 = long long;

i64 solve(double dx, double dy, int k, double cx, double cy, i64 n) {
  if (k == 0) {
    return n;
  }
  double grade = atan2(cy, cx) * 180.0 / PI;

  if (grade < 0) {
    grade += 360;
  }
  if (grade < 45 || grade >= 315) {
    return solve(dx / 2, dy / 2, k - 1, cx - dx / 2, cy, 4ll * n);
  } else if (grade < 135 && grade >= 45) {
    return solve(dx / 2, dy / 2, k - 1, cx, cy - dy / 2, 4ll * n - 3);
  } else if (grade < 225 && grade >= 135) {
    return solve(dx / 2, dy / 2, k - 1, cx + dx / 2, cy, 4ll * n - 2);
  } else {
    return solve(dx / 2, dy / 2, k - 1, cx, cy + dy / 2, 4ll * n - 1);
  }
  return n;
}
int main() {
  int t;
  fin >> t;
  while (t--) {
    int k;
    double cx, cy, dx, dy;
    fin >> dx >> dy >> k >> cx >> cy;

    i64 ans(solve(1.0, 1.0, k, cx / dx, cy / dy, 1));

    fout << ans << '\n';
  }

  return 0;
}
