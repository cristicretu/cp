#include <fstream>

using namespace std;

ifstream fin("bomboane.in");
ofstream fout("bomboane.out");

const int mxn = 1e3;

int ans[1 + mxn][3];
int n, v[1 + mxn];

int main(void) {
  fin >> n;

  int s = 0;
  for (int i = 1; i <= n; ++i) {
    fin >> v[i];
    s += v[i];
  }

  if (s % n) {
    fout << "-1\n";
    return 0;
  }

  s /= n;

  bool ok = 1;

  int imin, imax;
  int idx(0);

  while (ok) {
    int mn = (1 << 30) - 1;
    int mx = (1 >> 30) - 1;

    for (int i = 1; i <= n; ++i) {
      if (v[i] > mx) {
        mx = v[i]; 
        imax = i;
      }
      if (v[i] < mn) {
        mn = v[i];
        imin = i;
      }
    }

    if (mn == mx) {
      ok = 0;
      break;
    } else {
      ans[++idx][0] = imax;
      ans[idx][1] = imin;
      ans[idx][2] = s - mn;

      v[imin] = s;
      v[imax] = mx - (s - mn);
    }
  }

  fout << idx << '\n';

  for (int i = 1; i <= idx; ++i, fout << '\n') {
    for (int j = 0; j < 3; ++j) {
      fout << ans[i][j] << ' ';
    }
  }

  return 0;
}
