#include <bits/stdc++.h>

void solve()
{
  int64_t power, health;
  int n;
  std::cin >> power >> health >> n;
  std::vector<int> v(n);
  for (auto &i : v)
    std::cin >> i;
  for (auto a : v)
  {
    int b;
    std::cin >> b;
    health -= (b + power - 1) / power * a;
  }
  std::cout << (health + *max_element(v.begin(), v.end()) > 0 ? "YES\n"
                                                              : "NO\n");

  return;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}
