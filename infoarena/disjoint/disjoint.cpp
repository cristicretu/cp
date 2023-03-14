#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

ifstream fin("disjoint.in");
ofstream fout("disjoint.out");

static const int mxn = 1e5;

int n, m;
int tata[mxn + 1];

void read();
void solve();
void unif(int x, int y);
void query(int x, int y);
int find(int x);

int main() {
  read();
  solve();
  return 0;
}

int find(int x) {
  if (tata[x] == 0) {
    return x;
  }
  int k = find(tata[x]);
  tata[x] = k;
  return k;
}

void unif(int x, int y) { tata[find(x)] = y; }

void query(int x, int y) {
  if (find(x) == find(y)) {
    fout << "DA\n";
  } else {
    fout << "NU\n";
  }
}

void solve() {
  int op, x, y;
  while (m--) {
    fin >> op >> x >> y;

    if (op == 1) {
      unif(x, y);
    } else if (op == 2) {
      query(x, y);
    }
  }
}

void read() {
  fin >> n >> m;

  // for (int i = 1; i <= n; ++i) {
  //   tata[i] = i;
  // }
}
