#include <fstream>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

ifstream fin("pamant.in");
ofstream fout("pamant.out");

using VVI = vector<vector<int>>;
using VI = vector<int>;
using VB = vector<bool>;
using SI = set<int>;

int n, m;
VVI G;
VI idx, low, niv, t;
VB V;
SI artic;

int cnt;
int root;
int nr;

void read();
void tarjan(int x);

int main() {
  read();

  VI teams;
  for (int x = 1; x <= n; ++x) {
    if (!V[x]) {
      teams.emplace_back(x);

      root = x;
      nr = 0;
      tarjan(x);
      if (nr > 1) artic.insert(x);
    }
  }

  fout << teams.size() << '\n';
  for (auto i : teams) {
    fout << i << ' ';
  }
  fout << '\n';
  fout << artic.size() << '\n';
  for (auto i : artic) {
    fout << i << ' ';
  }
  fout << '\n';

  return 0;
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

void tarjan(int x) {
  V[x] = true;
  idx[x] = low[x] = ++cnt;

  niv[x] = niv[t[x]] + 1;

  if (niv[x] == 2) {
    // son of root
    nr++;
  }

  for (const int& y : G[x]) {
    if (y == t[x]) continue;

    if (!V[y]) {
      t[y] = x;

      tarjan(y);

      low[x] = min(low[x], low[y]);

      if (low[y] >= idx[x] && x != root) {
        artic.insert(x);
      }
    } else {
      low[x] = min(low[x], idx[y]);
    }
  }
}