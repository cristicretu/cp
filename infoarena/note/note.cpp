#include <iostream>
#include <fstream>

std::fstream fin("note.in", std::ios::in);
std::fstream fout("note.out", std::ios::out);

const int mxn = 1030, mxm = 130;

int v, n, dp[mxn][mxn], fv[mxm][mxn];

int main(){
	fin >> v >> n;
  for (int i = 1; i <= v; ++i){
    for (int j = 1; j <= n; ++j){
      int x;
      fin >> x;
      fv[x][j] = 1;
    }
  }

  int m;
  fin >> m;
  for (int j = 1; j <= m; ++j){ dp[j][0] = j;}
  for (int j = 1; j <= n; ++j){ dp[0][j] = j;}

  for (int i = 1; i <= m; ++i){
    int x;
    fin >> x;
    for (int j = 1; j <= n; ++j){
      if (fv[x][j] == 1){ dp[i][j] = dp[i - 1][j - 1];}
      else { dp[i][j] = 1 + std::min(dp[i - 1][j - 1], std::min(dp[i - 1][j], dp[i][j - 1])); }
    }
  }

  std::cerr<<dp[m][n];
  fout << dp[m][n] << '\n';
  return 0;
}
