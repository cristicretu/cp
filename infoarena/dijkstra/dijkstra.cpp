#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <tuple>

using namespace std;

ifstream fin("dijkstra.in", std::ios::in);
ofstream fout("dijkstra.out", std::ios::out);

const int INF = 0x3f3f3f3f;

using PI = pair<int,int>;
using VI = vector<int>;
using VP = vector<PI>;
using VVP = vector<VP>;

int n, m;
VVP G;
VI dist;

void read();
void write();
void dijkstra(int x, VI& d);

int main() {
  read();
  dijkstra(1, dist);
  write();
  return 0; 
}

void dijkstra(int x, VI& d) {
  priority_queue<PI, VP, greater<PI> > Q;
  d = VI(n + 1, INF);
  d[x] = 0;

  Q.emplace(0, x);
  while (!Q.empty()) {
    auto [dx, x] = Q.top();
    Q.pop();

    if (dx > d[x]) continue;

    for (auto node : G[x]) {
      auto [y, w] = node;
      if (d[y] > dx + w) {
        d[y] = dx + w;
        Q.emplace(d[y], y);
      }
    }
  }
}

void read() {
  fin >> n >> m;
  G = VVP(n + 1);

  int x, y, w;
  while (m--) {
    fin >> x >> y >> w;
    G[x].emplace_back(y, w);
  }
}

void write() {
  for (int i = 2; i <= n; ++i) {
    if (dist[i] != INF) {
      fout << dist[i] << ' ';
    } else {
      fout << 0 << ' ';
    }
  }
  fout << '\n';
}
