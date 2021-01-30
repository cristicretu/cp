#include <bits/stdc++.h>

std::ifstream fin("kprime.in");
std::ofstream fout("kprime.out");

const int mxn = 1e5 + 10;

std::bitset<1005> ciur;

int fr[mxn];

int main() {
  ciur[1] = 1, ciur[0] = 1;
  for (int i = 4; i <= 1005; i += 2) ciur[i] = 1;
  for (int i = 3; i * i <= 1005; i += 2)
    if (!ciur[i]) {
      for (int j = i * i; j <= 1005; j += i) ciur[j] = 1;
    }

  int n, k, ans = 0, count = 0;
  fr[0] = 1;
  fin >> n >> k;
  for (int i = 0; i < n; ++i) {
    int x;
    fin >> x;
    if (!ciur[x]) count++;
    if (count >= k) ans += fr[count - k];
    ++fr[count];
  }
  fout << ans;
  return 0;
}
