#include <fstream>
#include <iostream>

std::fstream fin("bifrunze.in", std::ios::in);
std::fstream fout("bifrunze.out", std::ios::out);

int main() {
  int n;
  fin >> n;

  for (int i = 1; i <= n; ++i) {
    int x, y, z;
    fin >> x >> y >> z;
    if (y == 0 && z == 0) {
      fout << i << ' ';
    }
  }
  return 0;
}
