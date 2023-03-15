#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

ifstream fin("apm.in");
ofstream fout("apm.out");

using PI = pair<int, int>;
using VI = vector<int>;
using VP = vector<PI>;
using VB = vector<bool>;
using VVP = vector<VP>;
using ul = unsigned long;

static const int INF = 0x3f3f3f3f;

ul n, m;
VVP G;
VI dist, t;
VB V;
ul cost;

void read();
void prim(int x);
void write();

int main() {
  read();
  prim(1);
  write();
  return 0;
}

void write() {
  int s = 0;
  for (int i = 2; i <= n; ++i) {
    s += dist[i] == INF ? 0 : dist[i];
  }
  fout << s << '\n' << n - 1 << '\n';
  for (int i = 2; i <= n; ++i) {
    fout << t[i] << ' ' << i << '\n';
  }
}

void prim(int x) {
  priority_queue<PI, VP, greater<PI>> Q;
  dist[x] = 0;
  Q.emplace(0, x);
  while (!Q.empty()) {
    auto [weight, node] = Q.top();
    Q.pop();

    if (V[node]) {
      continue;
    }
    V[node] = true;

    for (auto [y, w] : G[node]) {
      if (dist[y] > w && !V[y]) {
        dist[y] = w;
        t[y] = node;
        Q.emplace(w, y);
      }
    }
  }
}

void read() {
  fin >> n >> m;
  G = VVP(n + 1);
  dist = VI(n + 1, INF);
  t = VI(n + 1);
  V = VB(n + 1);

  int x, y, w;
  while (m--) {
    fin >> x >> y >> w;

    G[x].emplace_back(y, w);
    G[y].emplace_back(x, w);
  }
}
