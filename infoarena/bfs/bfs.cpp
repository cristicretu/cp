#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

ifstream fin("bfs.in");
ofstream fout("bfs.out");

using ll = long long;
#define mod 1000000007

const int Nmax = 100000;

int n, m, s;
int dist[Nmax];
vector<int>mat[Nmax];
queue<int> cords;

void solve();
void read();
void bfs();

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll test=1;
  //cin>>test;

  while(test--)
  {
    solve();
  }

  for (int i = 1; i <= n; ++i) {
    fout << dist[i] << ' ';
  }
  fout << '\n';

  return 0;
}

void bfs() {
  cords.push(s);

  while (!cords.empty()) {
    int node = cords.front();
    cords.pop();

    for (auto v: mat[node]) {
      if (dist[v] == -1) {
        dist[v] = 1 + dist[node];
        cords.push(v);
      }
    }
  }
}

void solve() {
  read();

  for (int i = 0; i <= n; ++i) {
    dist[i] = -1;
  }
  dist[s] = 0;

  bfs();
}

void read() {
  fin >> n >> m >> s;
  for (int i = 0; i < m; ++i) {
    int a, b;
    fin >> a >> b;

    mat[a].push_back(b);
  }
}
