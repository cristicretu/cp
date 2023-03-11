#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

using ll = unsigned long long;
using VLL = vector<vector<ll>>;

std::fstream fin("kfib.in", std::ios::in);
std::fstream fout("kfib.out", std::ios::out);

static const ll M = 666013;
static const ll M2 = (ll)M * M;

ll k;

VLL cn(int a, int b) { return vector<vector<ll>>(a, vector<ll>(b)); }

VLL mult(VLL a, VLL b) {
  VLL c = cn(a.size(), b[0].size());
  for (int i = 0, n = a.size(); i < n; ++i) {
    for (int k = 0, m = b.size(); k < m; ++k) {
      for (int j = 0, o = b[0].size(); j < o; ++j) {
        c[i][j] += a[i][k] * b[k][j];

        if (c[i][j] >= M2) {
          c[i][j] -= M2;
        }
      }
    }
  }

  for (int i = 0, n = a.size(); i < n; ++i) {
    for (int k = 0, m = b[0].size(); k < m; ++k) {
      c[i][k] %= M;
    }
  }

  return c;
}

int main() {
  fin >> k;

  VLL r = {{0, 1}};
  VLL b = {{0, 1}, {1, 1}};

  while (k) {
    if (k & 1) {
      r = mult(r, b);
    }
    b = mult(b, b);
    k /= 2;
  }

  fout << r[0][0] << '\n';
  return 0;
}
