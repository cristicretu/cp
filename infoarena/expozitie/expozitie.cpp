#include <iostream>
#include <fstream>

std::fstream fin("expozitie.in", std::ios::in);
std::fstream fout("expozitie.out", std::ios::out);

static const int mxn = 500;

int n, k, d, r, dp[1 + mxn][1 + mxn];

int main(){
	fin >> n >> d >> k;
  r = (n - d * k);
  if (r < 0){
    /* std::cerr << r; */
   fout << "0\n";
   return 0;
  }

  if (r == 0){
    fout << "1\n";
    return 0;
  }

  for (int i = 1; i <= d; ++i){
    dp[1][i] = i;
  }

  for (int i = 1; i <= n; ++i){
    dp[i][1] = 1;
  }

  for (int i = 2; i <= n; ++i){
    for (int j = 2; j <= d; ++j){
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }

  std::cerr << dp[r][d];
  fout << dp[r][d] << '\n';
  return 0;
}
