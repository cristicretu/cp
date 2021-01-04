#include <bits/stdc++.h>

std::ifstream fin("cpal.in");
std::ofstream fout("cpal.out");

int main() {
  std::string s;
  std::vector<std::string> rem;
  while (getline(fin, s)) {
    rem.push_back(s);
  }
  for (auto str : rem) {
    int i(0), count(0);
    bool ok = false;
    while (str[i]) {
      int nr = 0;
      while (isdigit(str[i])) {
        nr = nr * 10 + str[i] - '0';
        ++i;
      }
      if (nr and ok == false) ok = true;
      if (nr & 1) count++;
      ++i;
    }
    fout << ((!ok or count > 1) ? "0\n" : "1\n");
  }
  return 0;
}
