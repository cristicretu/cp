#include <bits/stdc++.h>

std::ifstream fin("calatorie.in");
std::ofstream fout("calatorie.out");

const int mxn = 1e3 + 10;

long long dp[60][510], x[60], h[60];

int main() {
  int t;
  fin >> t;
  while (t--) {
    int n;
    fin >> n;

    for (int i = 1; i <= 500; ++i) {
      dp[1][i] = LLONG_MAX;
    }
    for (int i = 1; i <= n - 1; ++i) {
      fin >> x[i] >> h[i];
    }
  }
  return 0;
}
