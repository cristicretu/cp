#include <fstream>
#include <cmath>

using namespace std;

ifstream fin("eureni.in");
ofstream fout("eureni.out");

long long s;
short int n, e;

struct euren {
  long long val;
  int times;
} v[11];

int main(void) {
  fin >> s >> n >> e;

  v[0].val = 1;  
  for (int i = 1; i <= n; ++i) {
    v[i].val = pow(e, i); 
    v[i].times = 0;
  }

/*   for (int i = 0; i <= n; ++i) { */
/*     fout << v[i].val << ' ' << v[i].times << '\n'; */
/*   } */

  int poz = n;
  int ans = 0;
  while (s > 0 && poz >= 0) {
    if (s - v[poz].val >= 0) {
      s -= v[poz].val;
      v[poz].times += 1;
      ans += 1;
    } else {
      poz -= 1;
    }
  }

  for (int i = n; i >= 0; --i) {
    if (v[i].times) {
      fout << v[i].val << ' ' << v[i].times << '\n';
    }
  }

  fout << ans << '\n';
  return 0;
}
