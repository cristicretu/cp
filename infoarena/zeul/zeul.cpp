#include <bits/stdc++.h>

std::ifstream fin("zeul.in");
std::ofstream fout("zeul.out");

const int mxn = 1e5 + 10;

int n, m;
int n_group[mxn], m_group[mxn];
std::vector<int> v(mxn);

int main() {
  fin >> n >> m;

  for (size_t i = 1; i <= m; ++i) {
    int a, b;
    fin >> a >> b;
    v[a]++, v[b]--;
  }

  int x(0), y(0);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= abs(v[i]); ++j) {
      if (v[i] >= 0)
        m_group[x++] = i;
      else
        n_group[y++] = i;
    }
  }

  fout << x << '\n';
  for (int i = 0; i < x; ++i, fout << '\n')
    fout << n_group[i] << ' ' << m_group[i];
  return 0;
}
