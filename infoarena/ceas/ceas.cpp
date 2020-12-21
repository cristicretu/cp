/**
 *    author: etohirse
 *    created: 21.12.2020 18:09:25
 **/
#include <fstream>

std::ifstream fin("ceas.in");
std::ofstream fout("ceas.out");

int main() {
  int h1, h2, m1, m2;
  fin >> h1 >> m1 >> h2 >> m2;
  if (h1 == 12) h1 = 0;
  int M1 = h1 * 60 + m1, M2 = h2 * 60 + m2;
  if (!(M1 % 65)) M2 -= 5;
  while (M2 > 0) {
    M1 = (M1 + 1) % 720;
    if (!(M1 % 65)) M2 -= 5;
    M2 -= 1;
  }
  fout << (M1 / 60 == 0 ? 12 : M1 / 60) << ' ' << M1 % 60;
  return 0;
}
