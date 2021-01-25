#include <bits/stdc++.h>

std::ifstream fin("par.in");
std::ofstream fout("par.out");

int main() {
  int n;
  fin >> n;
  std::string s;
  fin >> s;
  if (n & 1) {
    fout << -1;
    return 0;
  }
  int cnt = 0, ans = 0;
  for (int i = 0u; i < s.size(); ++i) {
    if (s[i] == '(')
      cnt++;
    else {
      if (cnt > 0)
        cnt--;
      else
        ans++, cnt++;
    }
  }
  fout << ans + (cnt + 1) / 2;
  return 0;
}
