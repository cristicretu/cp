#include <iostream>
#include <vector>

auto *in = fopen("sediu.in", "r");
auto *out = fopen("sediu.out", "w");

const int maxn = 16e3;

std::vector<int> mat[1 + maxn];
int sol[1 + maxn];
int vecinCount[1 + maxn];
int n;

void dfs(int node, int last = 0) {
  vecinCount[node] = 1;

  for (auto vecin : mat[node]) {
    if (vecin != last) {
      dfs(vecin, node);
      vecinCount[node] += vecinCount[vecin];
      sol[node] = std::max(sol[node], vecinCount[vecin]);
    }
  }
  sol[node] = std::max(sol[node], n - vecinCount[node]);
}

int main() {
  int i;
  fscanf(in, "%d\n", &n);

  int x, y;
  for (i = 1; i < n; ++i) {
    fscanf(in, "%d %d\n", &x, &y);

    mat[x].push_back(y);
    mat[y].push_back(x);
  }

  dfs(1);
  std::vector<int> s;
  int ans(1 << 30);

  for (i = 1; i <= n; ++i) {
    if (sol[i] < ans) {
      s.clear();
      s.push_back(i);
      ans = sol[i];
    } else if (sol[i] == ans) {
      s.push_back(i);
    }
  }

  fprintf(out, "%d %d\n", ans, s.size());

  for (auto vecin : s) {
    fprintf(out, "%d ", vecin);
  }
  return 0;
}
