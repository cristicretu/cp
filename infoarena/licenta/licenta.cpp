#include <bits/stdc++.h>

typedef long long ll;

std::ifstream fin("licenta.in");
std::ofstream fout("licenta.out");

const int mxn = 1e5 + 2;

int k, n, m;

int main() {
  fin >> k;

  fin >> n;
  std::vector<std::pair<int, int>> a(n);
  for (auto &i : a) fin >> i.first >> i.second;

  fin >> m;
  std::vector<std::pair<int, int>> b(m);
  for (auto &i : b) fin >> i.first >> i.second;

  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  int lb = 0, rb = 0;
  while (lb < n and rb < m) {
    int x = std::max(a[lb].first, b[rb].first),
        y = std::min(a[lb].second, b[rb].second);

    if (y - x >= k) {
      fout << x << ' ' << x + k;
      return 0;
    }

    if (a[lb].second < b[rb].second)
      ++lb;
    else if (a[lb].second > b[rb].second)
      ++rb;
    else
      ++lb, ++rb;
  }
  fout << -1;
  return 0;
}
