/**
 *    author: etohirse
 *    created: 27.12.2020 11:47:01
 **/
#include <bits/stdc++.h>

std::ifstream fin("agitatie.in");
std::ofstream fout("agitatie.out");

const int mxn = 3e3 + 2;
int lg[mxn];

struct cand {
  int agit, sens;
  void add() { agit += sens; }
} av[mxn];

int main() {
  int n;
  fin >> n;
  for (int i = 1; i <= n; ++i) {
    fin >> av[i].agit >> av[i].sens;
    lg[i] += lg[i - 1] + av[i].agit;
  }
  for (int i = 1; i <= mxn; ++i)
    for (int i = 1; i <= n; ++i) {
      av[i].add();
      if (av[i].agit == 0 and av[i].sens == -1) av[i].sens *= (-1);
      if (lg[i - 1] + av[i].agit < lg[i]) lg[i] = lg[i - 1] + av[i].agit;
    }
  fout << lg[n];
  return 0;
}
