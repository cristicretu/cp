/**
 *    author: etohirse
 *    created: 26.12.2020 15:54:25
 **/
#include <fstream>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

std::ifstream fin("beyond_the_wall.in");
std::ofstream fout("beyond_the_wall.out");

const int mxn = 4e4;
std::pair<int, int> av[mxn];

int main() {
  int n, q;
  fin >> n >> q;
  for (int i = 0; i < n; ++i) {
    fin >> av[i].first >> av[i].second;
  }

  while (q--) {
    int a, b, nr = 0;
    long long ans;
    fin >> a >> b;

    for (int i = 0; i < n; ++i) {
      ans = a * av[i].first - av[i].second + b;
      nr += (ans > 0);
    }

    fout << nr << '\n';
  }
  return 0;
}
