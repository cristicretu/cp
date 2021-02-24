#include <cstring>
#include <fstream>
#include <iostream>

std::fstream fin("expresie3.in", std::ios::in);
std::fstream fout("expresie3.out", std::ios::out);

std::string s;
int i;
char ch = 'a';

int solve() {
  int ans = 0, semn = 1;

  while (s[i] && s[i] != ')') {
    if (s[i] == '/') {
      semn = -1;
    } else if (s[i] == '*') {
      semn = 1;
    } else if (s[i] == '(') {
      ++i;
      ans += semn * solve();
    } else if (s[i] == ch) {
      ans += semn;
    }

    // std::cerr << ans;
    ++i;
  }

  // std::cerr << '\n' << ans;
  return ans;
}

int main() {
  fin >> s;

  // for (int j = 0; j < (int)s.size(); ++j) {
  //   if (islower(s[j])) {
  //     i = 0;
  //     ch++;
  //     fout << s[j] << ' ' << solve() << '\n';
  //   }
  // }

  for (int j = 0; j < 26; ++j, ++ch) {
    int t = s.find(ch);
    if (t != std::string::npos) {
      i = 0;
      fout << ch << ' ' << solve() << '\n';
    }
  }
  return 0;
}
