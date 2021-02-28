#include <iostream>
#include <fstream>

std::fstream fin("scara5.in", std::ios::in);
std::fstream fout("scara5.out", std::ios::out);

static const int mxn = 2e3;

int n, v[1 + mxn], dp[1 + mxn][1 + mxn], sol[1 + mxn];

int main(){
	fin >> n;

  for (int i = 1; i <= n; ++i){
    fin >> v[i];
  }

  for (int i = 1; i <= n; ++i){
    dp[i][1] = i;
    for (int k = 2; k <= i; ++k){
      dp[i][k] = dp[i - 1][dp[i - 1][k - 1]];
    }
  }

  for (int i = 1; i <= n; ++i){
    sol[dp[n][i]] = v[i];
  }

  for (int i = 1; i <= n; ++i){
    fout << sol[i] << ' ';
  }
  return 0;
}
