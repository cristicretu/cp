#include <bits/stdc++.h>

std::ifstream fin("teren2.in");
std::ofstream fout("teren2.out");

int main() {
  int n, d;
  fin >> n >> d;

  std::vector<std::pair<int, int>> v(n);
  for (auto& i : v) fin >> i.first >> i.second;

  int mutare = 30005, poz;
  for (int i = 0; i < n; ++i)
    if (abs(v[i].first) + abs(v[i].second) < mutare)
      poz = i, mutare = abs(v[i].first) + abs(v[i].second);

  if (v[poz].first > v[poz].second) {
  }

  v.push_back({v[0].first, v[0].second});

  long arie = 0;
  for (int i = 0; i < n; ++i)
    arie += v[i].first * v[i + 1].second - v[i + 1].first * v[i].second;

  return 0;
}
