#include <fstream>
#include <iostream>
#include <vector>

std::fstream fin("cerere.in", std::ios::in);
std::fstream fout("cerere.out", std::ios::out);

const int mxn = 1e5 + 1;

int n;
bool radacina[mxn];
int k[mxn], ans[mxn], steps;
std::vector<int> mat[mxn], temp;

void dfs(int node) {
  temp.push_back(node);

  steps += 1;

  if (k[node]) {
    ans[node] = ans[temp[steps - k[node] - 1]] + 1;
  }

  for (auto vecin : mat[node]) {
    dfs(vecin);
  }

  temp.pop_back();

  steps -= 1;
}

int main() {
  fin >> n;

  for (int i = 1; i <= n; ++i) {
    fin >> k[i];
  }

  for (int i = 1; i < n; ++i) {
    int x, y;
    fin >> x >> y;
    radacina[y] = 1;
    mat[x].push_back(y);
  }

  int rad;
  for (int i = 1; i <= n; ++i) {
    if (!radacina[i]) {
      rad = i;
      break;
    }
  }

  dfs(rad);

  for (int i = 1; i <= n; ++i) {
    fout << ans[i] << ' ';
  }
  fout << '\n';
  return 0;
}