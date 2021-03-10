#include <iostream>
#include <vector>
#include <fstream>

std::fstream fin("cmlsc.in", std::ios::in);
std::fstream fout("cmlsc.out", std::ios::out);

static const int mxn = (1 << 10);

int n, m;
int a[1 + mxn], b[1 + mxn], dp[1 + mxn][1 + mxn];
std::vector<int>ans;

int main(){
  fin >> n >> m;
  for (int i = 1; i <= n; ++i){
    fin >> a[i];
  }
  for (int i = 1; i <= m; ++i){
    fin >> b[i];
  }

  for (int i = 1; i <= n; ++i){
    for (int j = 1; j <= m; ++j){
      if (a[i] == b[j]){
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
      }
      /* std::cerr << "AM AJUNS!"; */
    }
  }

  for (int i = n, j = m; i;){
    std::cerr << "AM AJUNS!";
    if (a[i] == b[j]){
      ans.push_back(a[i]);
      --i;
      --j;
    } else if (dp[i - 1][j] < dp[i][j - 1]){
      --j;
    } else {
      --i;
    }
  }

  fout << ans.size() << '\n';
  for (int i = ans.size() - 1; i >= 0; --i){
    fout << ans[i] << ' ';
  }
  return 0;
}
