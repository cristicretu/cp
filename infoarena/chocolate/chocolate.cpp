#include <bits/stdc++.h>

std::ifstream fin("chocolate.in");
std::ofstream fout("chocolate.out");

int main() {
  int T;
  fin >> T;
  while (T--) {
    int n, m, x, y;
    fin >> n >> m >> x >> y;

    // numarul de dreptunghiuri in afara (x, y) sa fie par
    fout << (bool)((x - 1) ^ (y - 1) ^ (n - x) ^ (m - y)) << '\n';
  }
  return 0;
}
