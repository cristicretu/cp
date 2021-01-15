#include <bits/stdc++.h>

typedef long long ll;

std::ifstream fin("teren2.in");
std::ofstream fout("teren2.out");

const int mxn = 1000005;

std::pair<int, int> v[mxn];

int main() {
  int n;
  ll d;
  fin >> n >> d;

  for (int i = 1; i <= n; i++) fin >> v[i].first >> v[i].second;
  v[n + 1] = v[1];
  v[0] = v[n + 1];

  ll arie = 0;
  for (int i = 1; i <= n; i++)
    arie += v[i].first * v[i + 1].second - v[i + 1].first * v[i].second;
  arie = abs(arie);
  ll ans = arie;
  long long dx[4] = {0, 0, d, -d}, dy[4] = {d, -d, 0, 0};
  for (int i = 1; i <= n; i++)
    for (int k = 0; k < 4; k++) {
      ll x = v[i].first + dx[k], y = v[i].second + dy[k], temp = arie;
      temp -= (v[i - 1].first * v[i].second - v[i].first * v[i - 1].second) +
              (v[i].first * v[i + 1].second - v[i + 1].first * v[i].second);

      temp += (v[i - 1].first * y - x * v[i - 1].second) +
              (x * v[i + 1].second - v[i + 1].first * y);
      ans = std::max(ans, 1LL * abs(temp));
    }
  fout << std::fixed << std::setprecision(6) << (double)ans / 2.0;
  return 0;
}
