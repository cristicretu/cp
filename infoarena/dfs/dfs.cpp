#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

std::ifstream fin("dfs.in");
std::ofstream fout("dfs.out");

using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;

unsigned n, m;
VVI G;
VB v;

void read();
void solve();
void dfs(int node);

int main() {
  read();
  solve();
  return 0;
}

void dfs(int node) {
  v[node] = true;
  
  for (const int& y : G[node]) {
    if (!v[y]) {
      dfs(y);
    }
  }
}

void read() {
  fin >> n >> m;
  v = VB(n + 1);
  G = VVI(n + 1);
  
  int x, y;
  while (m--) {
    fin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x); 
  }
}

void solve() {
  unsigned ans = 0;
  
  for (unsigned i = 1; i <= n; ++i) {
    if (!v[i]) {
      ++ans;
      dfs(i);
    }
  }
  
  fout << ans << '\n';
}