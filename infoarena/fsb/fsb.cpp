#include <bits/stdc++.h>

std::ifstream fin("fsb.in");
std::ofstream fout("fsb.out");

int main() {
  int n;
  fin >> n;
  std::string s;
  fin >> s;
  std::map<int, int> fr;
  fr[0] = 1;
  int count = 0, ans(0);
  for (char d : s) {
    count += (d == '1' ? 1 : -1);

    ans += fr[count];
    ++fr[count];
  }

  fout << ans;
  return 0;
}
