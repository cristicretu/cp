#include <bits/stdc++.h>

std::ifstream fin("comun.in");
std::ofstream fout("comun.out");

const int mxn = 25e4 + 5;

int n, v[mxn];

std::vector<bool> solve(std::vector<bool> a) {
  for (int i = 1; i < a.size(); ++i) {
    if (!a[i]) continue;
    int gcd = 0;

    for (int j = i + i; j < a.size(); j += i) {
      if (a[j]) {
        gcd = gcd ? std::__gcd(gcd, j % gcd) : j;
      }
    }

    if (gcd == i) {
      a[i] = 0;
    }
  }

  return a;
}

int main() {
  fin >> n;

  std::vector<bool> v(100001, 0);
  for (int i = 0; i < n; ++i) {
    int x;
    fin >> x;
    v[x] = 1;
  }

  v = solve(v);
  std::vector<int> ans;

  for (int i = 0; i < v.size(); ++i) {
    if (v[i]) ans.push_back(i);
  }

  fout << ans.size() << '\n';
  for (int i : ans) fout << i << ' ';
  return 0;
}
