/**
 *    author: etohirse
 *    created: 29.12.2020 18:56:20
 **/
#include <bits/stdc++.h>

std::ifstream fin("cerere.in");
std::ofstream fout("cerere.out");

const int mxn = 1e5 + 2;
int av[mxn], rem[mxn], count;
bool viz[mxn];

std::vector<int> mat[mxn], temp;

void DFS(int nod) {
  temp.push_back(nod);
  count += 1;
  if (av[nod]) rem[nod] = rem[temp[count - av[nod] - 1]] + 1;
  for (auto i : mat[nod]) DFS(i);
  temp.pop_back();
  count -= 1;
}

int main() {
  int n;
  fin >> n;
  for (int i = 1; i <= n; ++i) fin >> av[i];
  for (int i = 1; i < n; ++i) {
    int a, b;
    fin >> a >> b;
    viz[b] = 1;
    mat[a].push_back(b);
  }
  for (int i = 1; i <= n; ++i)
    if (viz[i] == 0) {
      DFS(i);
      break;
    }
  for (int i = 1; i <= n; ++i, fout << ' ') fout << rem[i];
  return 0;
}
