#include <bits/stdc++.h>

std::ifstream fin("aur.in");
std::ofstream fout("aur.out");

int main() {
  int n, c, k;
  fin >> c >> n;
  if (c != 1) fin >> k;
  std::string s = "";
  for (int i = 0; i < n; ++i) {
    int x;
    fin >> x;
    s += std::to_string(x);
  }

  if (c == 1)
    fout << s.size() << '\n';
  else if (c == 2)
    fout << s[k - 1] << '\n';
  else if (c == 3) {
    std::string now, best;
    for (int i = 0; i < k; ++i) now += s[i];
    best = now;
    for (int i = k; i < s.size(); ++i) {
      now = now.substr(1, now.size() - 1);
      now += s[i];
      best = max(best, now);
    }
    fout << best << '\n';
  }
}
