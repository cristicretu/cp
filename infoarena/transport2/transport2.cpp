#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

ifstream fin("transport2.in");
ofstream fout("transport2.out");

using PI = pair<unsigned int, unsigned int>;
using VI = vector<int>;
using VVP = vector<vector<PI>>;
using VB = vector<bool>;

unsigned int n, m, maxW;
VVP G;
VB V;

void read();
unsigned int solve();
bool check(unsigned int weight);
void dfs(unsigned int node, VB &viz, unsigned int weight);

int main() {
  read();
  fout << solve() << '\n';
  return 0;
}

unsigned int solve() {
  unsigned int lb = 1, rb = maxW, mb;
  while (lb <= rb) {
    mb = lb + (rb - lb) / 2;

    if (check(mb)) {
      lb = mb + 1;
    } else {
      rb = mb - 1;
    }
  }

  return rb;
}

bool check(unsigned int weight) {
  V = VB(n + 1, 0);
  dfs(1, V, weight);

  for (auto i : V) {
    cout << i << ' ';
  }
  cout << weight << '\n' << '\n';
  return V[n];
}

void dfs(unsigned int node, VB &viz, unsigned int weight) {
  viz[node] = true;
  for (auto [y, w] : G[node]) {
    if (!viz[y] && weight <= w) {
      dfs(y, viz, weight);
    }
  }
}

void read() {
  fin >> n >> m;
  G = VVP(n + 1);

  for (unsigned int x, y, w; m--;) {
    fin >> x >> y >> w;
    G[x].emplace_back(y, w);
    G[y].emplace_back(x, w);
    maxW = max(maxW, w);
  }
}