#include <bits/stdc++.h>

typedef long long ll;

const int mxn = 5e6 + 2;

int n, v, a[mxn], s[mxn];
unsigned long long m;

std::stack<int> stiva;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> n >> m >> v;

  ll actual = m * v * v / 2;

  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }

  for (int i = 1; i <= n; ++i) {
    ll val = actual;
    int last = i;
    while (!stiva.empty() && val > 0) {
      val += m * 10 * (a[last] - a[stiva.top()]);
      last = i + 1;
      stiva.pop();
    }
    std::cout << '\n';
    s[i] = (stiva.empty() ? 0 : stiva.top());
    stiva.push(i);
  }

  for (int i = 1; i <= n; ++i) {
    std::cout << s[i] << ' ';
  }
  return 0;
}
