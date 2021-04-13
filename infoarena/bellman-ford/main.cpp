#include <vector>
#include <tuple>
#include <iostream>
#include <queue>
#include <fstream>

std::ifstream fin("bellmanford.in");
std::ofstream fout("bellmanford.out");

static const int mxn = 5e4, INF = 2e9 + 7;
std::vector<std::pair<int,int> > adj[mxn + 5];
int n, m;
int distance[mxn + 5], pasi[mxn + 5];
std::queue<std::pair<int, int> > q;

int main(){
  fin >> n >> m;
  for (int t = 1; t <= m; ++t){
    int a, b, d;
    fin >> a >> b >> d;
    adj[a].push_back({b, d});
  }

  for (int i = 1; i <= n; ++i){
    distance[i] = INF;
  }
  distance[1] = 0;
  pasi[1] = 0;
  q.push({1, 0});

  while (!q.empty()){
    int i = q.front().first, j = q.front().second;
    q.pop();

    if (j != distance[i]){
      continue;
    }
    if (pasi[i] > n){
      fout << "Ciclu negativ!\n";
      return 0;
    }

    for (auto e : adj[i]){
      if (distance[e.first] > j + e.second){
        distance[e.first] = j + e.second;
        pasi[e.first] = pasi[i] + 1;
        q.push({e.first, distance[e.first]});
      }
    }
  }

  for (int i = 2; i <= n; ++i){
    fout << distance[i] << ' ';
  }
  fout << '\n';
  return 0;
}
