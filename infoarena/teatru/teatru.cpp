#include <bits/stdc++.h>

std::ifstream fin("teatru.in");
std::ofstream fout("teatru.out");

int v[200], n, k, st, dr, ans;

std::string s;

int main() {
  fin >> n >> k >> s;
  int i = 0, j = 0, cnt = 0;
  while (j < n) {
    ++v[s[j]];
    if (v[s[j]] == 1) ++cnt;
    while (cnt > k) {
      --v[s[i]];
      if (v[s[i]] == 0) --cnt;
      ++i;
    }

    if (j - i + 1 > ans) {
      ans = j - i + 1;
      st = i, dr = j;
    }
    ++j;
  }
  fout << ans << '\n';
  for (int i = st; i <= dr; ++i) fout << s[i];
  return 0;
}
