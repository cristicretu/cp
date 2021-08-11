#include <bits/stdc++.h>

// #include <algorithm>
#include <fstream>
#include <iostream>

std::fstream fin("heap.in", std::ios::in);
std::fstream fout("heap.out", std::ios::out);

int n, H[100001];

void push_up(int k) {
  while (k > 1) {
    if (H[k] <= H[k / 2])
      return;
    else
      std::swap(H[k], H[k / 2]), k /= 2;
  }
}

void push_down(int k, int n) {
  while (2 * k <= n) {
    int p = 2 * k;
    if (p + 1 <= n && H[p + 1] > H[p]) p++;
    if (H[k] >= H[p])
      return;
    else
      std::swap(H[p], H[k]), k = p;
  }
}

int cnt = 0;

int main() {
  int n;
  fin >> n;
  for (int i = 1; i <= n; ++i) {
    int c, x;
    fin >> c;
    if (c == 1)
      fin >> x, H[++cnt] = x, push_up(cnt);
    else
      fout << H[1] << '\n', H[1] = H[cnt], cnt--, push_down(1, cnt);
  }
  return 0;
}