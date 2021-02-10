#include <bits/stdc++.h>

std::ifstream fin("distincte.in");
std::ofstream fout("distincte.out");

const int mxn = 1e5 + 5, M = 666013;

int a[mxn];

void solve(int i, int j) {
  long long ans = 0;
  std::unordered_set<int> s;
  for (int k = i; k <= j; ++k) {
    s.insert(a[k]);
  }

  for (auto it : s) {
    ans += it;
    ans %= M;
  }

  fout << ans << '\n';
}

int main() {
  int n, k, m;
  fin >> n >> k >> m;

  for (int i = 0; i < n; ++i) {
    fin >> a[i];
  }

  while (m--) {
    int a, b;
    fin >> a >> b;

    if (a != 1) a--;
    solve(a - 1, b - 1);
  }
  return 0;
}
