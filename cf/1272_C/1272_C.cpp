#include <iostream>
#include <fstream>

using ll = long long;

const int mxn = 2 * 1e5;

int n, k;
std::string s;
bool chars[26];

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> n >> k >> s;

  for (int i = 0; i < k; ++i) {
    char c;
    std::cin >> c;

    chars[c - 'a'] = 1;
  }

  ll dp[mxn + 1];
  ll ans = 0;

  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    if (chars[s[i] - 'a'] == 0) {
      dp[i + 1] = 0;
    } else {
      dp[i + 1] = 1 + dp[i];
    }

    ans += dp[i + 1];
  }

  std::cout << ans << '\n';
  
  return 0;
}
