#include <bits/stdc++.h>

typedef long long ll;

std::ifstream fin("ambuscada2.in");
std::ofstream fout("ambuscada2.out");

ll sum, last, first(-1), ans;

int main() {
  ll n, m, v;
  fin >> n >> m >> v;

  std::map<int, int> mp;
  while (m--) {
    int a, b, z;
    fin >> a >> b >> z;
    mp[a] += z;
    if (b < n) mp[b + 1] -= z;
  }
  mp[n] += 0;
  for (auto P : mp) {
    sum += P.second;
    if (sum >= v) {
      if (first == -1) first = P.first;
      last = P.first;
    } else {
      if (first != -1) {
        ans += P.first - first;
        first = -1;
      }
    }
  }
  if (first != -1) ans += last - first + 1;
  fout << n - ans;
  return 0;
}
