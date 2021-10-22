#include <iostream>
#include <fstream>

std::fstream fin("crescator.in", std::ios::in);
std::ofstream fout("crescator.out", std::ios::out);

static const int mxn = 3e5;

int n, v[1 + mxn], dp[1 + mxn];

int main(){
  fin >> n;
  for (int i = 1; i <= n; ++i){
    fin >> v[i];
  }

  for (int i = 1; i <= n; ++i){
    if (v[i] > 0) dp[i] = dp[i - 1];
    else if (v[i] == 0){
      int j;
      for (j = i + 1; j <= n && v[j] <= 0; ++j);
      dp[i] = v[j] - v[i];
    }
    else if (v)
  }
  return 0;
}
