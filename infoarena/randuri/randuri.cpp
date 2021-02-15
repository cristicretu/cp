#include <bits/stdc++.h>

std::ifstream fin("randuri.in");
std::ofstream fout("randuri.out");

std::vector<std::string> v;
const int mxN = 105;

int n, a[mxN];

int ans;

bool lcs(int x, int y) {
  int lg[mxN][mxN] = {0};
  int xst = v[x].size() - 1, yst = v[y].size() - 1;

  for (int i = xst; i >= 0; i--) {
    for (int j = yst; j >= 0; j--) {
      if (v[x][i] == v[y][j]) {
        lg[i][j] = lg[i + 1][j + 1] + 1;
      } else {
        lg[i][j] = std::max(lg[i + 1][j], lg[i][j + 1]);
      }
    }
  }
  return lg[0][0] > 6;
}

void elimina(int poz) {
  for (int i = poz; i < n; i++) a[i] = a[i + 1];
  n--;
}

int main() {
  std::string s;

  while (getline(fin, s)) v.push_back(s);

  n = v.size();
  for (int i = 0; i < n; i++) a[i] = i;

  bool ok = true;
  while (ok) {
    ok = false;

    for (int i = 1; i < n - 1; i++) {
      if (lcs(a[i - 1], a[i + 1])) {
        elimina(i);
        ok = true;
        ans++;
      }
    }
  }
  fout << ans << '\n';
  return 0;
}
