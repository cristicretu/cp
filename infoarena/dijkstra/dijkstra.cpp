#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

ifstream fin("dijkstra.in", std::ios::in);
ofstream fout("dijkstra.out", std::ios::out);

const int mxn = 50001;
const int INF = (1 << 30);

int n, m;
int dist[mxn];
bool viz[mxn];

struct cmp {
  bool operator ()(int x, int y) {
    return dist[x] < dist[y];
  }
};

vector<pair<int, int> > mat[mxn];
priority_queue<int, vector<int>, cmp> cords;

void solve();
void read();
void dijkstra(int node);

int main() {
  solve();
  return 0;
}

void dijkstra(int node) {
  viz[node] = true;
  dist[node] = 0;
  cords.push(node);

  while (!cords.empty()) {
    int newNode = cords.top();
    cords.pop();
    viz[newNode] = false;

    for (auto vecin: mat[newNode]) {
      if (dist[vecin.first] > dist[newNode] + vecin.second) {
        dist[vecin.first] = dist[newNode] + vecin.second; 

        if (!viz[vecin.first]) {
          viz[vecin.first] = true;
          cords.push(vecin.first);
        }
      }
    }
  }
}

void solve() {
  read();

  for (int i = 1; i <= n; ++i) {
    dist[i] = INF;
  }

  dijkstra(1);

  for (int i = 2; i <= n; ++i) {
    if (dist[i] != INF) fout << dist[i] << ' ';
    else fout << 0 << ' ';
  }
  fout << '\n';
}

void read() {
  fin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int a, b, d;
    fin >> a >> b >> d;
    mat[a].push_back({b, d});
  }
}