#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

#define int long long

std::fstream fin("mxl.in", std::ios::in);
std::fstream fout("mxl.out", std::ios::out);

static const int mxn = 40, mxk = 40 * 40;

int n, k;
int ans[1 + mxn][1 + mxn];
std::string mat[1 + mxn][1 + mxn];

int solve(int a, int b){
  if (ans[a][b]){
    return ans[a][b];
  }

  int total = 0;
  std::string s = mat[a][b];
  if (s[0] != '='){
    int nr = 0;
    for (int i = 0; '0' <= s[i] && s[i] <= '9' &&
        i < (int)s.size(); nr = nr * 10 + (s[i] - '0'), ++i);
    return ans[a][b] = nr;
  }

  for (int i = 1; i < (int)s.size();){
    int x = 0;
    for (; '0' <= s[i] && s[i] <= '9'; x = x * 10 + (s[i] - '0'), ++i);
    
    if (s[i] == ':'){
      int y = 0;
      ++i;
      for (; '0' <= s[i] && s[i] <= '9'; y = y * 10 + (s[i] - '0'), ++i);
      total += solve(x, y);
      ++i;
    } else {
      total += x;
      ++i;
    }
  }
  return ans[a][b] = total;
}

int32_t main(){
  fin >> n >> k;
  for (int i = 1; i <= k; ++i){
    int a, b;
    std::string s;
    fin >> a >> b >> s;
    mat[a][b] = s;
  }

  for (int i = 1; i <= n; ++i, fout << '\n'){
    for (int j = 1; j <= n; ++j){
      ans[i][j] = solve(i, j);
      fout << ans[i][j] << ' ';
    }
  }
}
