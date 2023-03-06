#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

ifstream fin("bfs.in");
ofstream fout("bfs.out");

using ll = long long;
using VI = vector<int>;
using VVI = vector<VI>;

int n, m, source;
VVI G;
VI dist;

void read();
void bfs(int start);
void write();

int main() {
  read();
  bfs(source);
  write();
}

void read() {
  fin >> n >> m >> source;
  G = VVI(n + 1);
    
  int x, y;
  while(m--) {
    fin >> x >> y;
    G[x].emplace_back(y); 
  }
}

void bfs(int start) {
  dist = VI(n + 1, -1);
  dist[start] = 0;
  queue<int> Q;
  
  Q.push(start);
  while(!Q.empty()) {
    int x = Q.front();
    Q.pop();
    
    for (auto node : G[x]) {
      if (dist[node] == -1) {
        dist[node] = 1 + dist[x];
        Q.push(node);
      }
    }
  }
}

void write() {
  for (int i = 1; i <= n; ++i) {
    fout << dist[i] << ' ';
  }
  fout << '\n';
}