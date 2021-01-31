#include <bits/stdc++.h>

std::ifstream fin("vila2.in");
std::ofstream fout("vila2.out");

const int mxn = 1e5 + 2;
int n, k, v[mxn], ans;
std::deque<int> hmax, hmin;

int main() {
  fin >> n >> k;
  for (int i = 1; i <= n; ++i) fin >> v[i];
  for (int i = 1; i <= n; ++i) {
    while (!hmax.empty() && v[i] >= v[hmax.back()]) hmax.pop_back();
    while (!hmin.empty() && v[i] <= v[hmin.back()]) hmin.pop_back();

    hmin.push_back(i), hmax.push_back(i);
    if (hmax.front() == i - k - 1) hmax.pop_front();
    if (hmin.front() == i - k - 1) hmin.pop_front();

    if (i > k) ans = std::max(ans, v[hmax.front()] - v[hmin.front()]);
  }
  fout << ans;
  return 0;
}
