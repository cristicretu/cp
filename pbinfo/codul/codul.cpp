#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

std::fstream fin("codul.in", std::ios::in);
std::fstream fout("codul.out", std::ios::out);

#define mymax(a, b) ((a > b) ? a : b);

static const int mxn = 200;

int n, m, dp[1 + mxn][1 + mxn], sir[1 + mxn], bst;
std::string a, b, subsir[1 + mxn][1 + mxn];

std::vector<char> ans;

int main(){
	fin >> a >> b;
  n = static_cast<int>(a.size());
  m = static_cast<int>(b.size());

  a = '*' + a, b = '*' + b;

  for (int i = 1; i <= n; ++i){
    for (int j = 1; j <= m; ++j){
      if (a[i] == b[j]){
        dp[i][j] = 1 + dp[i - 1][j - 1];
        subsir[i][j] = subsir[i - 1][j - 1] + a[i];
      } else {
        if (dp[i - 1][j] > dp[i][j - 1]){
          subsir[i][j] = subsir[i - 1][j];
        } else if (dp[i - 1][j] < dp[i][j - 1]){
          subsir[i][j] = subsir[i][j - 1];
        } else {
          subsir[i][j] = mymax(subsir[i - 1][j], subsir[i][j - 1]);
        }
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  std::cerr<<subsir[n][m];
  fout << subsir[n][m];

  return 0;
}
