#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

ifstream fin("clepsidra.in");
ofstream fout("clepsidra.out");

#define MOD 666013
using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;

int n, m;
VVI G;
VI idx, low, power, ans;
VB V;

void tarjan(int x, int tata);
void pwr();
void read();
void write();

int main() {
  read();
  pwr();
  tarjan(1, 0);
  write();
  return 0;
}

void read() {
  fin >> n >> m;
  G = VVI(n + 1);
  idx = low = power = ans = VI(n + 1);
  V = VB(n + 1);

  int x, y;
  while (m--) {
    fin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
}

void tarjan(int x, int tata) {
  V[x] = true;
  idx[x] = low[x] = idx[tata] + 1;
  int nr = x == 1 ? 0 : 1;

  for (const int& y : G[x]) {
    if (y == tata) continue;

    if (!V[y]) {
      tarjan(y, x);

      if (low[y] >= idx[x]) {
        ++nr;
      }
      low[x] = min(low[x], low[y]);
    } else {
      low[x] = min(low[x], idx[y]);
    }
  }
  ans[x] = power[nr];
}

void pwr() {
  power[0] = 1;
  for (int i = 1; i <= n; ++i) {
    power[i] = (power[i - 1] * 2) % MOD;
  }

  for (int i = 1; i <= n; ++i) {
    power[i] = (power[i] + MOD - 2) % MOD;
  }
}

void write() {
  for (auto it = ans.begin() + 1; it != ans.end(); it++) {
    fout << *it << '\n';
  }
}