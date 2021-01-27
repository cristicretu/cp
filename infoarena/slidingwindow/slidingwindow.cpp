#include <bits/stdc++.h>

std::ifstream fin("slidingwindow.in");
std::ofstream fout("slidingwindow.out");

const int mxn = 1e6 + 2;

int n, d, k = INT_MAX;

std::pair<int, int> v[mxn];

int main() {
  fin >> n >> d;

  for (int i = 0; i < n; ++i) {
    fin >> v[i].first;
    v[i].second = i;
  }
  std::sort(v, v + n);

  for (int i = 0; i < n; ++i) {
    int j = i + 1;
    while (abs(v[j].first - v[i].first) <= k) {
      if (abs(v[i].second - v[j].second) <= d)
        k = std::min(abs(v[j].first - v[i].first), k);
      ++j;
    }
  }
  fout << k << ' ';
  return 0;
}
