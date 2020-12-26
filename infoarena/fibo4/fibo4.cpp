/**
 *    author: etohirse
 *    created: 26.12.2020 11:17:10
 **/
#include <fstream>
#include <vector>

std::ifstream fin("fibo4.in");
std::ofstream fout("fibo4.out");

const int mxn = 1e6 + 2, M = 666013;
std::vector<int> fib, am;

int main() {
  fib.resize(1332028);
  fib[1] = 1;
  for (int i = 2; i < 1332028; ++i) fib[i] = (fib[i - 1] + fib[i - 2]) % M;

  int n, m;
  fin >> n >> m;
  am.resize(n + 3);
  while (m--) {
    int x, y;
    unsigned long long z;
    fin >> x >> y >> z;
    am[x] = (am[x] + fib[z % 1332028]) % M;
    am[x + 1] = (am[x + 1] + fib[(z - 1) % 1332028]) % M;
    am[y + 1] = (am[y + 1] - fib[(z + y - x + 1) % 1332028] + M) % M;
    am[y + 2] = (am[y + 2] - fib[(z + y - x) % 1332028] + M) % M;
  }

  for (int i = 2; i <= n; ++i) {
    am[i] = (am[i] + am[i - 1] + am[i - 2]) % M;
  }
  for (int i = 1; i <= n; ++i, fout << ' ') fout << am[i];
  return 0;
}
