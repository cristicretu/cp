#include <bits/stdc++.h>

int n, k;
std::string s;

std::queue<int> cords[2];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> n >> k >> s;
  int dir = 0;

  for (int i = 0; i < n; ++i) {
    if (s[i] == '*') cords[dir].push(i);
  }
  for (int i = 1; i <= k; ++i) {
    while (!cords[dir].empty()) {
      int i = cords[dir].front();
      cords[dir].pop();
      s[i] = '*';

      if (i < n - 1 and s[i + 1] == '.') cords[1 - dir].push(i + 1);
      if (i > 0 and s[i - 1] == '.') cords[1 - dir].push(i - 1);
    }
    dir = 1 - dir;
  }
  while (!cords[dir].empty()) {
    s[cords[dir].front()] = '*';
    cords[dir].pop();
  }
  std::cout << s;
}