#include <bits/stdc++.h>

std::ifstream fin("reactivi.in");
std::ofstream fout("reactivi.out");

bool cmp(const std::pair<int, int> a, const std::pair<int, int> b) {
  return a.second < b.second;
}

int main() {
  int n, ans = 0;
  fin >> n;
  std::vector<std::pair<int, int>> v(n);
  for (auto &i : v) fin >> i.first >> i.second;
  std::sort(v.begin(), v.end(), cmp);

  int last = v[0].second;
  for (int i = 1; i < n; ++i) {
    if (v[i].first > last) {
      last = v[i].second;
      ans++;
    }
  }
  fout << ans + 1;
  return 0;
}
