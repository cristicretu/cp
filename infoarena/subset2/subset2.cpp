#include <bits/stdc++.h>

std::ifstream fin("subset2.in");
std::ofstream fout("subset2.out");

int n, k;

int main() {
  fin >> n >> k;
  fout << (n / k) * ((k - 1) / 2) + 1 + std::min((k - 1) / 2, n % k) +
              (k + 1) % 2;
  return 0;
}