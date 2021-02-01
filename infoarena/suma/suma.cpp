#include <bits/stdc++.h>

typedef long long ll;

std::ifstream fin("suma.in");
std::ofstream fout("suma.out");

int main() {
  ll n, p, sum = 0;
  fin >> n >> p;

  n %= p;

  for (int i = 1; i <= n; ++i) {
    sum += i * (i - 1);

    if (sum >= p) sum %= p;
  }
  fout << sum;
  return 0;
}
