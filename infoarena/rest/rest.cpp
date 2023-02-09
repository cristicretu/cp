#include <cmath>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("rest.in");
ofstream fout("rest.out");

const int Dim = 250001;

int arb[4 * Dim], v[Dim];
int n, b, p, m;
int ans;

void Build(int node, int st, int dr) {
  if (st == dr) {
    fin >> arb[node];
    return;
  }

  int mid = (st + dr) / 2;
  Build(2 * node, st, mid);
  Build(2 * node + 1, mid + 1, dr);

  arb[node] = arb[node * 2] * v[dr - mid] % p + arb[node * 2 + 1] % p;
}

void Query(int node, int st, int dr, int a, int b) {
  if (st >= a && dr <= b) {
    ans = (ans * v[dr - st + 1] + arb[node]) % p;
    return;
  }
  int mid = (st + dr) >> 1;
  if (a <= mid) Query(2 * node, st, mid, a, b);
  if (b > mid) Query(2 * node + 1, mid + 1, dr, a, b);
}

void Update(int node, int st, int dr, int a, int b) {
  if (st == dr) {
    arb[node] = b % p;
    return;
  }

  int mid = (st + dr) >> 1;
  if (a <= mid)
    Update(2 * node, st, mid, a, b);
  else
    Update(2 * node + 1, mid + 1, dr, a, b);

  arb[node] = (arb[node * 2] * v[dr - mid] % p + arb[node * 2 + 1]) % p;
}

int main() {
  fin >> n >> b >> p;

  v[0] = 1;
  for (int i = 1; i <= n; ++i) v[i] = (v[i - 1] * b) % p;
  Build(1, 1, n);

  fin >> m;
  while (m--) {
    int a, x, y;
    fin >> a >> x >> y;

    if (a == 1)
      Update(1, 1, n, x, y);
    else {
      ans = 0;
      Query(1, 1, n, x, y);
      fout << ans << '\n';
    }
  }

  return 0;
}
