#include <bits/stdc++.h>

std::ifstream fin("matrice.in");
std::ofstream fout("matrice.out");

const int mxN = 3e4 + 5;

int n, m, a, r[mxN], c[mxN], ans, cnt;

void solve(int x, int y) {
  if (x > n || y > m) return;

  int mxzero(0), count0(0), mxone(0), count1(0);

  for (int i = x; i <= n; ++i) {
    int one = r[i] - r[i - x];
    int zero = x - one;

    if (one > mxone) {
      mxone = one, count1 = 0;
    }

    if (one == mxone) {
      count1++;
    }

    if (zero > mxzero) {
      mxzero = zero, count0 = 0;
    }

    if (zero == mxzero) {
      count0++;
    }
  }

  for (int i = y; i <= m; ++i) {
    int one = c[i] - c[i - y];
    int zero = y - one;

    int mx, nr;
    if (zero > one) {
      mx = x * one + mxzero * (zero - one), nr = count0;
    }

    if (zero < one) {
      mx = x * zero + mxone * (one - zero), nr = count1;
    }

    if (zero == one) {
      mx = x * zero, nr = n - x + 1;
    }

    if (ans < mx) {
      ans = mx, cnt = 0;
    }
    if (ans == mx) {
      cnt += nr;
    }
  }
}

int main() {
  fin >> n >> m >> a;

  for (int i = 1; i <= n; ++i) {
    fin >> r[i], r[i] += r[i - 1];
  }

  for (int j = 1; j <= m; ++j) {
    fin >> c[j], c[j] += c[j - 1];
  }

  int i = 1;
  for (; i * i < a; ++i) {
    if (a % i == 0) {
      solve(i, a / i);
      solve(a / i, i);
    }
  }

  if (i * i == a) solve(i, i);

  fout << ans << ' ' << cnt << '\n';
  return 0;
}
