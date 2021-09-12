#include <iostream>
#include <vector>
#include <fstream>

std::fstream fin("darb.in", std::ios::in);
std::fstream fout("darb.out", std::ios::out);

const int mxn = 100005;

int n;
int maxLvl, pozLvl;
std::vector<int>muchii[mxn];
bool viz[mxn];

void dfs(int nod, int lvl) {
  viz[nod] = 1;

  if (lvl > maxLvl) {
    maxLvl = lvl;
    pozLvl = nod;
  }

  for (auto vecin : muchii[nod]) {
    if (!viz[vecin]) {
      dfs(vecin, lvl + 1);
    } 
  }
}

int main(){
  fin >> n;

  for (int i = 0 ; i < n; ++i) {
    int x , y;
    fin >> x >> y;
    muchii[x].push_back(y);
    muchii[y].push_back(x);
  }

  dfs(1, 0);

  for (int i = 1; i <= n; ++i) {
    viz[i] = 0;
  }

  dfs(pozLvl, 0);

  fout << maxLvl + 1 << '\n';
  return 0;
}
