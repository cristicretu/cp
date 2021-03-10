#include <bits/stdc++.h>

std::ifstream fin("rucsac.in");
std::ofstream fout("rucsac.out");

static const int mxn = 5e4;

int n, g, w[1 + mxn], p[1 + mxn], ans[1 + mxn];

int main(){
  fin >> n >> g;
  for (int i = 1; i <= n; ++i){
    fin >> w[i] >> p[i];
  }

  int rez = 0;
  for (int i = 1; i <= n; ++i){
    for (int j = g - w[i]; j >= 0; --j){
      if (ans[j + w[i]] < ans[j] + p[i]){
        ans[j + w[i]] = ans[j] + p[i];
        rez = std::max(ans[j + w[i]], rez);
      }
    }
  }

  fout << rez << '\n';
  return 0;
}
