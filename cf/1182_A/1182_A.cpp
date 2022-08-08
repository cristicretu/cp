#include <iostream>
#include <fstream>
#include <cmath>

int n;
int dp[61];


int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std:: cin >> n;

  // Math
  // if (n & 1 || n < 2) {
  //   std::cout << "0\n";
  //   return 0;
  // }

  // std::cout << int(std::pow(2, n / 2)) << '\n';

  // DP
  dp[0] = 1;

  for (int i = 2; i <= n; i += 2) {
    dp[i] = dp[i - 2] * 2;
  }

  std::cout << dp[n] << '\n';
  return 0;
}

