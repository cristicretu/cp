#include <bits/stdc++.h>

typedef long long ll;

std::ifstream fin("rogvaiv.in");
std::ofstream fout("rogvaiv.out");

const int mxn = 5e4 + 10;

ll n, c, M, a[mxn], b[mxn], nr;

int main() {
  fin >> c >> n >> M;

  a[7] = nr = c;
  if (c == 1) {
    for (int i = 7; i <= n; ++i) {
      a[i] = (a[i - 1] * 7 + nr - a[i - 7] + M) % M;
      nr = (nr * 7) % M;
    }
  } else {
    for (int i = 7; i <= n; ++i) {
      b[i] = (nr - a[i - 7] * 2 - b[i - 6] + 3 * M) % M;
      a[i] = (7 * a[i - 1] + b[i]) % M;
      nr = (nr * 7) % M;
    }
  }
  fout << a[n];
  return 0;
}
