#include <bits/stdc++.h>

std::ifstream fin("expresie2.in");
std::ofstream fout("expresie2.out");

int i, ans, numere;
std::string s;

int solve() {
  if (s[i] == '(') {
    int mx = -1e9, ans = 0;
    while (s[i] != ')') {
      ++i;
      if (ans < 0) ans = 0;
      ans += solve();
      mx = std::max(mx, ans);
    }
    ++i;

    return mx;
  }

  if (s[i] == '[') {
    std::vector<int> v;
    while (s[i] != ']') {
      ++i;
      v.push_back(solve());
    }
    ++i;

    int k = (v.size() - 1) / 2;
    nth_element(v.begin(), v.begin() + k, v.end());
    return v[k];
  }

  int nr = 0, semn = 1;
  while (('0' <= s[i] && s[i] <= '9') || (s[i] == '-')) {
    if ('0' <= s[i] && s[i] <= '9')
      nr = nr * 10 + s[i] - '0';
    else
      semn = -1;
    ++i;
  }

  ++numere;

  return nr * semn;
}

int main() {
  fin >> s;
  ans = solve();
  while (s[i] == ',') {
    ++i;
    ans += solve();
  }

  fout << numere << '\n' << ans;
  return 0;
}
