#include <bits/stdc++.h>

std::ifstream fin("deque.in");
std::ofstream fout("deque.out");

int n, k;

unsigned long long ans;

std::deque<std::pair<int, int>> dq;

int32_t main() {
  fin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    int x;
    fin >> x;
    while (!dq.empty() && dq.back().first > x) dq.pop_back();
    dq.push_back({x, i});
    if (dq.front().second == i - k) dq.pop_front();
    if (i >= k) ans += dq.front().first;
  }
  fout << ans << '\n';
  return 0;
}
