#include <bits/stdc++.h>

std::ifstream fin("dijkstra.in");
std::ofstream fout("dijkstra.out");

const int mxn = 5e4 + 5, inf = (1 << 30);

int n, m;
int d[mxn];

bool inq[mxn];

std::vector<std::pair<int, int>> g[mxn];

struct cmp {
  bool operator()(int x, int y) { return d[x] > d[y]; }
};

std::priority_queue<int, std::vector<int>, cmp> cords;

void Dijkstra(int nod) {
  for (int i = 1; i <= n; i++) d[i] = inf;

  d[nod] = 0;

  cords.push(nod);
  inq[nod] = true;

  while (!cords.empty()) {
    int current = cords.top();
    cords.pop();

    inq[current] = false;
    for (size_t i = 0; i < g[current].size(); i++) {
      int Vecin = g[current][i].first;
      int Cost = g[current][i].second;
      if (d[current] + Cost < d[Vecin]) {
        d[Vecin] = d[current] + Cost;
        if (inq[Vecin] == false) {
          cords.push(Vecin);
          inq[Vecin] = true;
        }
      }
    }
  }
}

int main() {
  fin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int x, y, cost;
    fin >> x >> y >> cost;
    g[x].push_back({y, cost});
  }

  Dijkstra(1);

  for (int i = 2; i <= n; ++i) {
    fout << (d[i] != inf ? d[i] : 0) << ' ';
  }
  return 0;
}
