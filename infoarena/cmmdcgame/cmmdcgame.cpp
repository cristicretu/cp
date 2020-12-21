/**
 *    author: etohirse
 *    created: 21.12.2020 16:36:06
 **/
#include <fstream>

std::ifstream fin("cmmdcgame.in");
std::ofstream fout("cmmdcgame.out");

const int mxN = 3e5 + 10;
int T, N, X;
int cir[mxN];

int main() {
  int prm = 0;
  for (int i = 2; i <= 300000; i++) {
    if (!cir[i]) {
      cir[i] = (++prm);
      for (int j = 2 * i; j <= 300000; j += i) {
        if (!cir[j]) cir[j] = prm;
      }
    }
  }
  fin >> T;
  while (T--) {
    fin >> N;
    int ans(0);
    for (int i = 1; i <= N; ++i) {
      fin >> X;
      ans ^= cir[X];
    }
    if (!ans)
      fout << "J\n";
    else
      fout << "D\n";
  }
  return 0;
}
