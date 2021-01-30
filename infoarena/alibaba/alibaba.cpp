#include <bits/stdc++.h>

std::ifstream fin("alibaba.in");
std::ofstream fout("alibaba.out");

const int mxn = 1e4 + 10;

char s[mxn], st[mxn];

int main() {
  int n, k, top = 0;
  fin >> n >> k >> (s + 1);
  k = n - k;
  for (int i = 1; i <= n; ++i) {
    while (top > 0 && i <= n - k + top && s[i] > st[top]) --top;
    if (top < k) st[++top] = s[i];
  }
  fout << (st + 1);
  return 0;
}
