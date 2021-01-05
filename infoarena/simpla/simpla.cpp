#include <bits/stdc++.h>

std::ifstream fin("simpla.in");
std::ofstream fout("simpla.out");

int s(int n) {
  if (!n) return 0;
  return s(n / 10) + n % 10;
}

int sum(int n) {
  if (n & 1) return (n - 1) / 2;
  if (s(n + 1) & 1) return n / 2;
  return n / 2 - 1;
}

int main() {
  int a, b;
  fin >> a >> b;
  fout << sum(b) - sum(a - 1);
  return 0;
}
