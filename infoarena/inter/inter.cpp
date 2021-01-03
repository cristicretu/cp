#include <bits/stdc++.h>

std::ifstream fin("inter.in");
std::ofstream fout("inter.out");

const int mxn = 1e3 + 5;

std::pair<int, int> av[mxn];

int main() {
  int n, m;
  fin >> n >> m;

  for (int i = 1; i <= n; ++i) av[i].first = i;
  while (m--) {
    int a, b;
    fin >> a >> b;
    av[std::max(a, b)].second--;
    av[std::min(a, b)].second++;
  }
  for (int i = 1; i <= n; ++i) av[i + av[i].second].first = i;
  for (int i = 1; i <= n; ++i, fout << ' ') fout << av[i].first;
  return 0;
}
