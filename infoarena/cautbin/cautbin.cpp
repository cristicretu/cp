#include <bits/stdc++.h>

std::ifstream fin("cautbin.in");
std::ofstream fout("cautbin.out");

int main() {
  using namespace std;

  int n, m;
  fin >> n;

  vector<int> v(n);
  for (auto &i : v) fin >> i;
  sort(v.begin(), v.end());

  fin >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    fin >> a >> b;

    if (a == 0) {
      int ans = upper_bound(v.begin(), v.end(), b) - v.begin() - 1;
      fout << (ans >= 0 and ans < n and v[ans] == b ? ans + 1 : -1) << '\n';
    } else if (a == 1) {
      int ans = lower_bound(v.begin(), v.end(), b + 1) - v.begin() - 1;
      fout << ans + 1 << '\n';
    } else if (a == 2) {
      int ans = upper_bound(v.begin(), v.end(), b - 1) - v.begin();
      fout << ans + 1 << '\n';
    }
  }
  return 0;
}
