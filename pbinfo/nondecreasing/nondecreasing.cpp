#include <bits/stdc++.h>

std::ifstream fin("nondecreasing.in");
std::ofstream fout("nondecreasing.out");

const int mxn = 50e3 + 10;

int n, t[mxn], a[30][mxn];
std::string s;

int Cost(int i, int j) {
  if (i != j) return i + j;
  return 0;
}

int main() {
  fin >> s;
  n = s.size();
  s = ' ' + s;
  for (int i = 1; i <= n; ++i) {
    t[i] = s[i] - 'a' + 1;
  }

  for (int j = 1; j <= n; ++j) {
    for (int i = 1; i <= 26; ++i) {
      a[i][j] = Cost(i, j);
    }
  }

  for (int i = 1; i <= 26; ++i) {
    a[i][1] = Cost(i, t[1]);
  }

  // for (int i = 1; i <= 26; ++i) {
  //   for (int j = 2; j <= n; ++j) {
  //     for (int k = 1; k <= i; ++k) {
  //       a[j][i] = std::min(a[k][j - 1] + Cost(i, t[j]), a[i][j]);
  //     }
  //   }
  // }

  for (int j = 2; j <= n; ++j) {
    for (int i = 1; i <= 26; ++i) {
      for (int k = 1; k <= i; ++k) {
        a[j][i] = std::min(a[k][j - 1] + Cost(i, t[j]), a[i][j]);
      }
    }
  }

  // int ans = 1e9;
  // for (int i = 1; i <= 26; ++i) {
  //   ans = std::min(i, a[i][n - 1]);
  // }

  // fout << ans;

  for (int i = 1; i <= 26; ++i, fout << '\n') {
    for (int j = 1; j <= n; ++j) {
      fout << a[i][j] << ' ';
    }
  }
  return 0;
}
