#include <bits/stdc++.h>

std::ifstream fin("litere.in");
std::ofstream fout("litere.out");

int n, rem[30], ans;

int q(int j) {
  int ans = 0;
  for (int i = j; i; i -= i & -i) ans += rem[i];
  return ans;
}

void u(int j) {
  for (int i = j; i <= 30; i += i & -i) rem[i]++;
}

int main() {
  fin >> n;
  for (int i = 0; i < n; ++i) {
    char c;
    fin >> c;

    ans += i - q((int)c - 'a' + 1);
    u((int)c - 'a' + 1);
  }
  fout << ans;
  return 0;
}
