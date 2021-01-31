#include <bits/stdc++.h>

std::ifstream fin("chiftea.in");
std::ofstream fout("chiftea.out");

int main() {
  int t;
  fin >> t;
  while (t--) {
    int n;
    fin >> n;
    if (n) {
      int x = sqrt(n);
      fout << (2 * ((n - x * x + x - 1) / x) + 4 * x) << '\n';
    } else {
      fout << "0\n";
    }
  }
  return 0;
}
