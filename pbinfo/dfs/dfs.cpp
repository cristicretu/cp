#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

std::ifstream fin("dfs.in");
std::ofstream fout("dfs.out");

const int maxn = 101;

int n, m, x;
std::vector<int> mat[maxn];
bool viz[maxn];

void dfs(int node) {
  fout << node << ' ';
  viz[node] = true;

  for (auto vecin: mat[node]) {
    if (!viz[vecin]) {
      dfs(vecin);
    }
  }
}

int main(void) {
  fin >> n >> m >> x;

  for (int i = 0; i < m; ++i) {
    int a, b;
    fin >> a >> b;

    mat[a].push_back(b);
    mat[b].push_back(a);
  }

  for (int i = 0; i < n; ++i) {
    std::sort(mat[i].begin(), mat[i].end());
  }
  dfs(x);
}