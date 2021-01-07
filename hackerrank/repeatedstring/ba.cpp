#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);

  std::string s;
  std::cin >> s;
  long n, a(0);
  std::cin >> n;

  for (char d : s)
    if (d == 'a') ++a;

  a *= n / s.size();
  for (int i = 0; i < (n % s.size()); ++i)
    if (s[i] == 'a') ++a;

  std::cout << a;
  return 0;
}
