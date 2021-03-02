#include <iostream>
#include <fstream>
#include <climits>
#include <cstring>

typedef long long ll;

std::fstream fin("gaz.in", std::ios::in);
std::fstream fout("gaz.out", std::ios::out);

static const int mxn = 2000;
static const ll oo = LONG_MAX;

ll v[1 + mxn], s[1 + mxn], dp[1 + mxn], Cost[1 + mxn];
int l, p, d, c, n;

int main(){
	fin >> l >> p >> d >> c >> n;
  for (int i = 1; i <= n; ++i){
    fin >> v[i];
    s[i] = s[i - 1] + v[i];
  }

  /* std::cerr << oo; */
  for (int i = 1; i <= n; ++i){
    dp[i] = oo;
  }
  for (int i = 1; i <= n; ++i){
    for (int j = i; j >= 1; --j){
      Cost[j] = Cost[j + 1] + std::max(1LL * 0, 1LL * ((s[i] - s[j]) - l));
    }
    for (int j = 0; j < i; ++j){
      dp[i] = std::min(dp[i], dp[j] + Cost[j + 1] * c + p);
    }
  }

  std::cerr << dp[n];
  std::cerr << s[n];

  fout << dp[n] + d * s[n];
  return 0;
}
