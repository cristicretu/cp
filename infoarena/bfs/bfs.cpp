#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

std::fstream fin("bfs.in", std::ios::in);
std::fstream fout("bfs.out", std::ios::out);

const int mxn = 1000005;

int n, m, start;
std::vector<int> muchii[mxn];
std::queue<int> cords;
int dist[mxn];

void bfs() {
  int nod;
  
  while (!cords.empty()) {
    nod = cords.front();
    cords.pop();

    for (auto vec : muchii[nod]) {
      if (dist[vec] == -1) {
        cords.push(vec);
        dist[vec] = dist[nod] + 1;
      }
    }
  }
}

int main(){
	fin >> n >> m >> start;

  for (int i = 0; i < m; ++i) {
    int x, y;
    fin >> x >> y;
    muchii[x].push_back(y);
  }

  for (int i = 1; i <= n; ++i) {
    dist[i] = -1;
  }
  dist[start] = 0;

  cords.push(start);

  bfs();

  for (int i = 1; i <= n; ++i) {
    fout << dist[i] << ' ';
  }
  fout << '\n';


  return 0;
}
