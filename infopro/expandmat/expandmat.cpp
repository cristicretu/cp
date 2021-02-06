#include <bits/stdc++.h>

std::ifstream fin("expandmat.in");
std::ofstream fout("expandmat.out");

int n, q, ans = 0;

int main() {
  fin >> n >> q;
  while (q--) {
    int a, b, nr;
    char c;
    fin >> a >> b >> c;
    nr = c - 'a' + 1;

    int ans = 0;
    if (a <= n && b <= n) {
      if (a % 2 != b % 2) {
        if (a * b + 1 == nr) ans++, fout << "palit";
      }
      if (a * b == nr) ans++;
    } else if (a <= n && b > n) {
    }
    fout << ans << '\n';
  }
  fout << ans;
  return 0;
}

/*

  12 34
1 ab de
2 cd fg

3 wx dc
4 yz ba
*/