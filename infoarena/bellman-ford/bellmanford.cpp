#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

ifstream fin("bellmanford.in");
ofstream fout("bellmanford.out");

static const int INF = 0x3f3f3f3f;

using PI = pair<int, int>;
using VI = vector<int>;
using VP = vector<PI>;
using VVP = vector<VP>;
using ul = unsigned long;

ul n, m;
VVP G;
VI dist, steps;

void read();
void solve();

int main() {
  read();
  solve();
  return 0;
}

void solve() {
  queue<PI> Q;
  dist[1] = steps[1] = 0;
  Q.push({0, 1});

  while (!Q.empty()) {
    auto [w, y] = Q.front();
    Q.pop();

    if (w != dist[y]) {
      continue;
    }

    if (steps[y] > n) {
      fout << "Ciclu negativ!\n";
      return;
    }

    for (auto node : G[y]) {
      if (dist[node.first] > w + node.second) {
        dist[node.first] = w + node.second;
        Q.push({dist[node.first], node.first});
        steps[node.first] = steps[y] + 1;
      }
    }
  }

  for (int i = 2; i <= n; ++i) {
    fout << dist[i] << ' ';
  }
  fout << '\n';
}

void read() {
  fin >> n >> m;
  G = VVP(n + 1);
  dist = steps = VI(n + 1, INF);

  int x, y, w;
  while (m--) {
    fin >> x >> y >> w;
    G[x].emplace_back(y, w);
  }
}
