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
  return 0;
}
