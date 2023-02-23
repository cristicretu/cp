#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

ifstream fin("arbint.in");
ofstream fout("arbint.out");

int n, m;
vector<int> aib;

void Build(int lb, int rb, int node) {
  if (lb == rb) {
    fin >> aib[node];
    return;
  }

  int mb = (lb + rb) / 2;

  Build(lb, mb, node * 2);
  Build(mb + 1, rb, node * 2 + 1);

  aib[node] = max(aib[node * 2], aib[node * 2 + 1]);
}

int query(int lb, int rb, int a, int b, int node) {
  if (a <= lb && b >= rb) {
    return aib[node];
  }

  int mb = (lb + rb) / 2;
  int ans(0);

  if (a <= mb) {
    ans = max(ans, query(lb, mb, a, b, node * 2));
  }
  if (b > mb) {
    ans = max(ans, query(mb + 1, rb, a, b, node * 2 + 1));
  }

  return ans;
}

void update(int lb, int rb, int poz, int val, int node) {
  if (lb == rb) {
    aib[node] = val;
    return;
  }

  int mb = (lb + rb) / 2;

  if (mb >= poz) {
    update(lb, mb, poz, val, node * 2);
  } else {
    update(mb + 1, rb, poz, val, node * 2 + 1);
  }

  aib[node] = max(aib[node * 2], aib[node * 2 + 1]);
  return;
}

int main() {
  fin >> n >> m;
  aib.resize(4 * n);

  Build(1, n, 1);

  while (m--) {
    int q, a, b;

    fin >> q >> a >> b;

    if (q == 0) {
      fout << query(1, n, a, b, 1) << '\n';
    } else {
      update(1, n, a, b, 1);
    }
  }
}