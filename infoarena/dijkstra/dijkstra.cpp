#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <tuple>

using namespace std;

ifstream fin("dijkstra.in", std::ios::in);
ofstream fout("dijkstra.out", std::ios::out);

const int INF = 0x3f3f3f3f;

using PI = pair<int, int>;
using VI = vector<int>;
using VP = vector<PI>;
using VVP = vector<VP>;

unsigned n, m;
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

void read() {
  fin >> n >> m;
  G = VVP(n + 1);
  
  int x, y, w;
  while (m--) {
    fin >> x >> y >> w; 
    G[x].emplace_back(y, w);
  }
}

void dijkstra(int x, VI& d) {
  priority_queue<PI, VP, greater<PI> > Q;
  Q.emplace(0, x);
  
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

void write() {
  for (unsigned i = 2; i <= n; ++i) {
    if (dist[i] == INF) {
      fout << "0 ";
    } else {
      fout << dist[i] << ' ';
    }
  }
  fout << '\n';
}