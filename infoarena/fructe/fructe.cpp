#include <bits/stdc++.h>

typedef long long ll;

std::ifstream fin("fructe.in");
std::ofstream fout("fructe.out");

int main() {
  int t;
  fin >> t;
  while (t--) {
    ll p, b;
    fin >> p >> b;
    fout << (b & 1) << '\n';
  }
  return 0;
}
