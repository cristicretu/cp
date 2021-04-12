#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

std::ifstream fin("dfs.in");
std::ofstream fout("dfs.out");

static const int mxn = 105;

int n, m , x;
std::vector<int> adj[mxn];
bool viz[mxn];

void dfs(int node){
  fout << node << ' ';
  viz[node] = 1;
  
  for (auto u : adj[node]){
    if (!viz[u]) dfs(u);
  }
}

int main(){
  fin >> n >> m >> x;
  for (int i = 0; i < m; ++i){
    int a, b;
    fin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 1; i <= n; ++i){
    std::sort(adj[i].begin(), adj[i].end());
  }
  dfs(x);
  return 0;
}
