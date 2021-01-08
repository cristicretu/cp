#include <bits/stdc++.h>

std::vector<std::pair<char, int>> mp;

int main() {
  std::ios_base::sync_with_stdio(false);

  std::string s;
  std::cin >> s;

  std::map<int, int> mp, freq;
  for (char d : s) {
    mp[d]++;
  }

  for (auto it = mp.begin(); it != mp.end(); ++it) {
    freq[it->second]++;
  }
  int bal = 0, ans = 0;
  for (auto it = freq.begin(); it != freq.end(); ++it) {
    if (it->second > ans) {
      bal = it->first;
      ans = it->second;
    }
  }

  int count(0), del(0);
  for (auto it = mp.begin(); it != mp.end(); ++it) {
    if (it->second == 1 || it->second == bal - 1 || it->second == bal + 1)
      del++;
    else if (abs(it->second - bal) > 0)
      count++;
  }
  if (del < 2 and !count)
    std::cout << "YES";
  else
    std::cout << "NO";
  return 0;
}
