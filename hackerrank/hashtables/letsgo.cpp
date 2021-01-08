#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n), b(m);
  std::map<std::string, int> mpa;
  for (auto &i : a) std::cin >> i, mpa[i]++;
  for (auto &i : b) std::cin >> i;

  for (auto i : b) {
    if (mpa[i] > 0)
      mpa[i]--;
    else {
      std::cout << "No";
      return 0;
    }
  }
  std::cout << "Yes";

  return 0;
}
