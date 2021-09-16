# cplusplus
solutions to problems
```c++
#include <iostream>
#include <fstream>
#include <vector>

std::fstream fin("cerere.in", std::ios::in);
std::fstream fout("cerere.out", std::ios::out);

const int mxn = 1000001;

int n;
int viz[mxn];
int k[mxn];
std::vector<int> muchii[mxn];

int dfs(int node) {
  int ans(0);
  int vecin = muchii[node][0];
  if (k[vecin] == 0) {
    return ans;
  } 
  ans ++;
  ans += dfs(vecin);
  return ans;
}

int main(){
  fin >> n;

  for (int i = 1; i <= n; ++i) {
    fin >> k[i];
  }

  for (int i = 1; i < n; ++i) {
    int x, y;
    fin >> x >> y;

    muchii[x].push_back(y);
    // muchii[y].push_back(x);
  }

  for (int i = 1; i <= n; ++i) {
    if (k[i] == 0) {
      fout << "0 ";
    } else {
      fout << dfs(k[i]) << ' ';
    }
  }  

  fout << '\n';

  return 0;
}
```
