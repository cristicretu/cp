#include <fstream>
#include <algorithm>
#include <vector>
#include <iostream>

std::ifstream fin("sdistante.in");
std::ofstream fout("sdistante.out");

const int M = 1e9 + 7,
      sigma = 53,
        mxn = 4e6;

long long frec[1 + 2 * sigma];
int ap[1 + 2 * sigma];

long long dp[1 + mxn];

int cod(char c){
  if ('a' <= c && c <= 'z'){
    return c - 'a' + 1;
  }
  return c - 'A' + sigma;
}

int main(){
  std::string s;
  fin >> s;
  long long ans = 0;
  for (int i = 0; i < s.size(); ++i){
    dp[i] = dp[i - 1] + (i - ap[cod(s[i])]);
    if (dp[i] < 0){
      dp[i] += M;
    } else {
      dp[i] %= M;
    }

    ap[cod(s[i])]++;
    int k = i;
    long long number = (1LL * k - 1) * k / 2;
    dp[i] += number - frec[cod(s[i])];

    if (dp[i] < 0){
      dp[i] += M;
    } else {
      dp[i] %= M;
    }

    frec[cod(s[i])] += k;
    ans = (ans + dp[i]) % M;
  }
  std::cerr << ans;

  fout << ans;
  return 0;
}
