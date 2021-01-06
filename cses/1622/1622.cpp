#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);

  std::string s;
  std::cin >> s;
  std::vector<std::string> rem;
  std::sort(s.begin(), s.end());
  do {
    rem.push_back(s);
  } while (next_permutation(s.begin(), s.end()));
  std::cout << rem.size() << '\n';
  for (auto i : rem) std::cout << i << '\n';
  return 0;
}
