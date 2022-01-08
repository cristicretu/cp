#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>
#include <memory.h>

std::ifstream fin("BFS.in");
std::ofstream fout("BFS.out");

const int maxn = 105;

int n, m, x;
int dist[maxn];
std::vector<int> mat[maxn];
std::queue<int> cords;

void bfs() {
  cords.push(x);
	dist[x] = 0;
	while(!cords.empty()){
		int nod = cords.front();
		cords.pop();
		fout << nod << ' ';
		for (auto i : mat[nod]){
			if (dist[i] == -1){
				cords.push(i);
				dist[i] = dist[nod] + 1;
			}
		}
	}
}

int main(){
  memset(dist, -1, sizeof(dist));
  fin >> n >> m >> x;

  for (int i = 1; i <= m; ++i){
      int a, b;
      fin >> a >> b;
      mat[a].push_back(b), mat[b].push_back(a);
  }
  for (int i = 1; i <= n; ++i)
      std::sort(mat[i].begin(), mat[i].end());

  bfs();

  return 0;
}
