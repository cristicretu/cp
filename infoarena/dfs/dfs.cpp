#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

std::ifstream fin("dfs.in");
std::ofstream fout("dfs.out");

const int maxn = 100001;

int n, m, ans;
bool viz[maxn];
vector<int>mat[maxn];

void solve();
void dfs(int node);
void read();

int main() {
  solve();

  fout << ans << '\n';
  return 0;
}

void dfs(int node) {
  viz[node] = true;
  for (auto v: mat[node]) {
    if (!viz[v]) {
      dfs(v);
    }
  }
}

void solve() {
  read();

  for (int i = 1; i <= n; ++i) {
    if (!viz[i]) {
      ans += 1;
      dfs(i);
    }
  }
}

void read() {
  fin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int a, b;
    fin >> a >> b;
    mat[a].push_back(b);
    mat[b].push_back(a);
  }
}