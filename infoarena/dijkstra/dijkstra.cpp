#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

std::fstream fin("dijkstra.in", std::ios::in);
std::fstream fout("dijkstra.out", std::ios::out);

const int mxn = 50001;
const int INF = (1 << 30);

int n, m;
int dist[mxn];
bool inQ[mxn];

struct cmp {
  bool operator()(int x, int y) {
    return dist[x] > dist[y];
  }
};

std::vector<std::pair<int,int> > g[mxn];
std::priority_queue<int, std::vector<int>, cmp> cords;

void Dijkstra(int node) {
  dist[node] = 0;
  cords.push(node);
  inQ[node] = 1;

  while (!cords.empty()) {
    int newNode = cords.top();
    cords.pop();
    inQ[newNode] = 0;

    for (auto vecin : g[newNode]) {
      if (dist[newNode] + vecin.second < dist[vecin.first]) {
        dist[vecin.first] = dist[newNode] + vecin.second;
        if (!inQ[vecin.first]) {
          cords.push(vecin.first);
          inQ[vecin.first] = 1;
        }
      }
    }
  }
}

int main(){
  fin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int x, y, c;
    fin >> x >> y >> c;

    g[x].push_back({y, c});
  }

  for (int i = 1; i <= n; ++i) {
    dist[i] = INF;
  }

  Dijkstra(1);

  for (int i = 2; i <= n; ++i) {
    if (dist[i] != INF) {
      fout << dist[i] << ' ';
    } else {
      fout << "0 ";
    }
  }
  return 0;
}
