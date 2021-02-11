#include <bits/stdc++.h>

std::ifstream fin("dreptunghi.in");
std::ofstream fout("dreptunghi.out");

long long ans;

inline void solve(int a, int b) {
  if (!b) {
    return;
  }
  ans += a / b * b;
  solve(b, a % b);
}

int main() {
  int n, m;
  fin >> n >> m;
  solve(n, m);
  fout << ans << '\n';
  return 0;
}
