#include <iostream>
#include <fstream>
#include <vector>

std::fstream fin("dfs.in", std::ios::in);
std::fstream fout("dfs.out", std::ios::out);

const int mxN = 100005;

int n, m, ans;
bool viz[mxN];
std::vector<int>Muchii[mxN];

void dfs(int nod) {
    viz[nod] = 1;

    for (auto vecin : Muchii[nod]) {
      if (!viz[vecin]) {
        dfs(vecin);
      }
    }
}

int main(){
  fin >> n >> m;

  for (int i = 0; i < m; ++i) {
     int x, y;
     fin >> x >> y;
     Muchii[x].push_back(y);
     Muchii[y].push_back(x);
  }

  for (int i = 1; i <= n; ++i) {
      if (!viz[i]) {
          ans += 1;
          dfs(i);
      }
  }

  fout << ans << '\n';
  return 0;
}
