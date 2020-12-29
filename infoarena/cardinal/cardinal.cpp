/**
 *    author: etohirse
 *    created: 29.12.2020 11:49:05
 **/
#include <bits/stdc++.h>

std::ifstream fin("cardinal.in");
std::ofstream fout("cardinal.out");

int main() {
  int t;
  fin >> t;
  while (t--) {
    int n;
    fin >> n;
    if (n % 8 == 0)
      for (int i = 1; i <= n / 8; ++i) fout << "URDLDLUR";
    else if (n % 8 == 7) {
      fout << "URDRDLU";
      for (int i = 1; i <= (n - 7) / 8; ++i) fout << "RULDLDRU";
    } else
      fout << "IMPOSIBIL";
    fout << '\n';
  }
  return 0;
}
