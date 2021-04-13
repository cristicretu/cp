#include <iostream>
#include <queue>
#include <fstream>
#include <vector>

std::ifstream fin("bfs.in");
std::ofstream fout("bfs.out");

static const int mxn = 1e5 + 5;

int n, m, s;
int distance[mxn];
std::vector<int> adj[mxn];

inline void bfs(){
  std::queue<int> q;
  q.push(s);
  distance[s] = 0;

  while (!q.empty()){
    int node = q.front();
    q.pop();

    for (int i = 0; i < adj[node].size(); ++i){
      int node_next = adj[node][i];
      if (distance[node_next] == -1){
        q.push(node_next);
        distance[node_next] = distance[node] + 1;
      }
    }
  }
}

int main(){
  fin >> n >> m >> s;
  for (int i = 1; i <= m; ++i){
    int a, b;
    fin >> a >> b;
    adj[a].push_back(b);
  }
  for (int i = 1; i <= n; ++i){
    distance[i] = -1;
  }

  bfs();
  for (int i = 1; i <= n; ++i){
    fout << distance[i] << ' ';
  }
  fout << '\n';
  return 0;
}
