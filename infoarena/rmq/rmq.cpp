#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

ifstream fin("rmq.in");
ofstream fout("rmq.out");

int n, m;
vector<int> aib;

void build(int st, int dr, int node);
void update(int st, int dr, int a, int b);
int query(int st, int dr, int a, int b, int node = 1);

int main() {
  fin >> n >> m;
  aib = vector<int>(4 * n, 0);

  build(1, n, 1);

  int a, b;
  while (m--) {
    fin >> a >> b;
    fout << query(1, n, a, b, 1) << '\n';
  }
  return 0;
}

void build(int st, int dr, int node) {
  if (st == dr) {
    fin >> aib[node];
    return;
  }

  int mb = st + (dr - st) / 2;
  build(st, mb, 2 * node);
  build(mb + 1, dr, 2 * node + 1);

  aib[node] = min(aib[node * 2], aib[node * 2 + 1]);
  return;
}

void update(int st, int dr, int a, int b, int node) {
  if (st == dr) {
    aib[node] = b;
    return;
  }

  int mb = st + (dr - st) / 2;
  if (mb >= a) {
    update(st, mb, a, b, 2 * node);
  } else {
    update(mb + 1, dr, a, b, 2 * node + 1);
  }

  aib[node] = min(aib[node * 2], aib[node * 2 + 1]);
  return;
}

int query(int st, int dr, int a, int b, int node) {
  if (a <= st && b >= dr) {
    return aib[node];
  }

  int mb = st + (dr - st) / 2;
  int ans = 1 << 30;
  if (mb >= a) {
    ans = min(ans, query(st, mb, a, b, 2 * node));
  }
  if (b > mb) {
    ans = min(ans, query(mb + 1, dr, a, b, 2 * node + 1));
  }

  return ans;
}