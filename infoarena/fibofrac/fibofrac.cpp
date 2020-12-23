/**
 *    author: etohirse
 *    created: 23.12.2020 18:35:26
 **/
#include <fstream>

std::ifstream fin("fibofrac.in");
std::ofstream fout("fibofrac.out");

const int mxn = 1e6 + 2;
int n, av[mxn];

int main() {
  fin >> n;
  for (int i = 1; i <= n; ++i) av[i] = i - 1;
  for (int i = 2; i <= n; ++i)
    for (int j = 2 * i; j <= n; j += i) av[j] -= av[i];
  long long ans(0);
  for (int i = 1; i <= n; ++i) ans += ((i <= (n / 2)) ? 2 : 1) * av[i];
  fout << ans - n + 1;
  return 0;
}
