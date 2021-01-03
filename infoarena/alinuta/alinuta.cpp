#include <bits/stdc++.h>

std::ifstream fin("alinuta.in");
std::ofstream fout("alinuta.out");

const int mxn = 1e5 + 1;

int av[mxn];

int main() {
  int k, T;
  fin >> k >> T;

  int count(0);
  for (int i = 0; i < mxn; ++i) {
    if (av[i]) continue;
    if (i + count >= mxn) break;

    av[i] = i + count, av[i + count] = i;
    count += k + 1;
  }

  for (int i = 0; i < T; ++i) {
    int a, b;
    fin >> a >> b;
    if (a > b) std::swap(a, b);

    fout << (av[a] == b ? "B\n" : "A\n");
  }
  return 0;
}
