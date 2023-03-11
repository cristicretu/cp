#include <fstream>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

ifstream fin("biconex.in");
ofstream fout("biconex.out");

using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;
using SI = set<int>;

int n, m;
VVI G;
VI idx, low, niv, t;
VB V;
SI artic;
int cnt, nr, root;

void read();
void solve();
void tarjan(int node);

int main() {
  read();
  solve();
  return 0;
}

void solve() {
  for (int x = 1; x <= n; ++x) {
    if (!V[x]) {
      root = x;
      nr = 0;
      tarjan(x);

      if (nr > 1) {
        artic.insert(x);
      }
    }
  }

  for (auto i : t) {
    cout << i << ' ';
  }
}

void tarjan(int node) {
  V[node] = true;
  idx[node] = low[node] = ++cnt;
  niv[node] = niv[t[node]] + 1;

  if (niv[node] == 2) {
    nr++;
  }

  for (const int &y : G[node]) {
    if (y == t[node]) {
      continue;
    }

    if (!V[y]) {
      t[y] = node;
      tarjan(y);

      low[node] = min(low[node], low[y]);
      if (low[y] >= idx[node] && node != root) {
        // couldn't go higher than father
        artic.insert(node);
      }
    } else {
      low[node] = min(low[node], idx[y]);
    }
  }
}

void read() {
  fin >> n >> m;
  G = VVI(n + 1);
  V = VB(n + 1);
  idx = low = niv = t = VI(n + 1);

  int x, y;
  while (m--) {
    fin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
}