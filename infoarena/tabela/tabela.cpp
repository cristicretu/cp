/**
 *    author: etohirse
 *    created: 22.12.2020 20:12:12
 **/
#include <fstream>

std::ifstream fin("tabela.in");
std::ofstream fout("tabela.out");

int main() {
  int n, m;
  fin >> n >> m;
  fout << ((n - 1) xor (m - 1));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) return 0;
}
