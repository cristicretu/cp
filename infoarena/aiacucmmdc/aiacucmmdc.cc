/**
 *    author: etohirse
 *    created: 26.12.2020 16:27:29
 **/
#include <fstream>

std::ifstream fin("aiacucmmdc.in");
std::ofstream fout("aiacucmmdc.out");

long long sz, ans;

int main() {
  int n, d;
  fin >> n >> d;
  while (n--) {
    int x;
    fin >> x;
    if (x % d == 0)
      ++sz;
    else {
      ans += sz * (sz + 1) / 2;
      sz = 0;
    }
  }
  fout << ans + sz * (sz + 1) / 2;
  return 0;
}
