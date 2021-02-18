#include <bits/stdc++.h>

std::ifstream fin("euro2.in");
std::ofstream fout("euro2.out");

const int mxN = 1e4 + 10;

float v[mxN], vmn[mxN];
int lc[mxN], ld[mxN], t, ans;

int cautbin(int lb, int rb, float val) {
  if (vmn[rb] < val) return rb + 1;
  while (lb < rb) {
    int mb = (lb + rb) / 2;
    if (vmn[mb] >= val) {
      rb = mb;
    } else {
      lb = mb + 1;
    }
  }
  return lb;
}

int main() {
  fin >> t;
  for (int i = 1; i <= t; ++i) {
    fin >> v[i];
  }

  int lmax = 0, poz = 0;
  for (int i = 1; i <= t; ++i) {
    poz = cautbin(1, lmax, v[i]);
    vmn[poz] = v[i];
    lmax = std::max(lmax, poz);
    lc[i] = poz;
  }

  lmax = 0;
  for (int i = t; i >= 1; --i) {
    poz = cautbin(1, lmax, v[i]);
    vmn[poz] = v[i];
    lmax = std::max(lmax, poz);
    ld[i] = poz;
  }

  for (int i = 1; i <= t; ++i) {
    if (lc[i] > 1 && ld[i] >= 1) {
      ans = std::max(ans, lc[i] + ld[i] - 1);
    }
  }

  fout << (lc[t] == t ? 0 : ans);
  return 0;
}
