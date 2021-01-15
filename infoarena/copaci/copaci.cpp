#include <bits/stdc++.h>

std::ifstream fin("copaci.in");
std::ofstream fout("copaci.out");

int main() {
  int n;
  fin >> n;

  std::vector<std::pair<int, int>> v(n);
  for (auto& i : v) fin >> i.first >> i.second;
  v.push_back({v[0].first, v[0].second});

  long long arie = 0, latura = 0;
  for (int i = 0; i < n; ++i)
    arie += v[i].first * v[i + 1].second - v[i + 1].first * v[i].second,
        latura += std::__gcd(abs(v[i].first - v[i + 1].first),
                             abs(v[i].second - v[i + 1].second));
  fout << (arie - latura) / 2 + 1;

  return 0;
}

// A = ANS + PUNCTE / 2 - 1;
// teorema lui pick