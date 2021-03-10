#include <iostream>
#include <fstream>

std::fstream fin("stirling.in", std::ios::in);
std::fstream fout("stirling.out", std::ios::out);

static const int mxn = 1e3, M = 98999;

int n, s1[1 + mxn][1 + mxn], s2[1 + mxn][1 + mxn];

int main(){
  fin >> n;
  s1[1][1] = s2[1][1] = 1;
  for (int i = 2; i < mxn; ++i){
    for (int j = 1; j <= i; ++j){
      s1[i][j] = (s1[i - 1][j - 1] - (i - 1) * s1[i - 1][j]) % M;
    }

    for (int j = 1; j <= i; ++j){
      s2[i][j] = (s2[i - 1][j - 1] + j * s2[i - 1][j]) % M;
    }
  }

  while(n--){
    int c, a , b;
    fin >> c >> a >> b;
    if (c == 1){
      fout << s1[a][b] << '\n';
    } else {
      fout << s2[a][b] << '\n';
    }
  }
  return 0;
}
