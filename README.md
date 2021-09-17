# cplusplus
solutions to problems
```c++
#include <fstream>
#include <iostream>
#include <unordered_set>
#include <vector>

std::fstream fin("sediu.in", std::ios::in);
std::fstream fout("sediu.out", std::ios::out);

const int mxn = 16001;

int n;
bool viz[mxn];
int vecinCount[mxn];
std::vector<int> mat[mxn];

void dfs(int node) {
  vecinCount[node] = 1;

  for (auto vecin : mat[node]) {
    if (viz[vecin] == false) {
      viz[vecin] = true;
      dfs(vecin);
      vecinCount[node] += vecinCount[vecin];
    }
  }
}

int main() {
  fin >> n;

  for (int i = 1; i <= n; ++i) {
    int x, y;
    fin >> x >> y;

    mat[x].push_back(y);
    mat[y].push_back(x);
  }

  viz[1] = true;
  dfs(1);

  int ans(4000000);
  std::vector<int> ss;
  for (int i = 1; i <= n; ++i) {
    int mx(0);

    mx = n - vecinCount[i];

    for (auto vecin : mat[i]) {
      mx = std::max(mx, vecinCount[vecin]);
    }

    if (mx < ans) {
      ss.clear();
      ss.push_back(i);
      ans = mx;
    } else if (mx == ans) {
      ss.push_back(i);
    }
  }

  fout << ans << ' ' << ss.size() << '\n';

  for (int i = 1; i <= n; ++i) {
    int mx(0);

    mx = n - vecinCount[i];

    for (auto vecin : mat[i]) {
      mx = std::max(mx, vecinCount[vecin]);
    }

    if (mx == ans) {
      fout << i << ' ';
    }
  }

  return 0;
}
```
