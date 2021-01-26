#include <bits/stdc++.h>

std::ifstream fin("grid.in");
std::ofstream fout("grid.out");

const int mxn = 2e4 + 2;

int n, q;

int main() {
  fin >> n >> q;

  std::deque<int> dq[3];

  int x = 0;
  for (int j = 0; j <= 2; j++)
    for (int i = 1; i <= n; i++) dq[j].push_back(++x);

  while (q--) {
    int a, b, c, d;
    fin >> a >> c >> b >> d;

    int temp = dq[a][c];
    dq[a].erase(dq[a].begin() + c);
    dq[b].insert(dq[b].begin() + d, temp);
  }

  for (int i = 0; i <= 2; ++i, fout << '\n')
    for (auto a : dq[i]) fout << a << ' ';
  return 0;
}
