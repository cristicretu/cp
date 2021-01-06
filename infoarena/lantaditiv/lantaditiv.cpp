#include <bits/stdc++.h>

std::ifstream fin("lantaditiv.in");
std::ofstream fout("lantaditiv.out");

int main() {
  long long n;
  fin >> n;
  std::vector<long long> v;
  v.push_back(n);
  while (n != 1) {
    if (n & 1)
      n--;
    else
      n /= 2;
    v.push_back(n);
  }
  fout << v.size() << '\n';
  for (int i = v.size() - 1; i >= 0; --i) fout << v[i] << ' ';
  return 0;
}
