#include <bits/stdc++.h>

std::ifstream fin("miting.in");
std::ofstream fout("miting.out");

static const int mxn = 61, mxc = 10, mxv = 3601, oo = 1 << 13,
                 dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

short cost[mxc][mxc][mxv];
int n, m, mat[mxn][mxn];
std::string cuv;
char a[mxn][mxn];
std::deque<std::pair<int, int>> dq;
std::queue<short> q;

inline void lee(int x, int y) {}

int main() {
  int c, imin = mxn, imax = -1, jmin = mxn, jmax = -1, i, j, k;

  fin >> c >> n >> m >> cuv;

  for (i = 0; i < n; ++i) {
    fin.getline(a[i], 101);
    for (j = 0; j < m; ++j) {
      if (isupper(a[i][j])) {
        dq.push_front({i, j});
        imin = std::min(imin, i), imax = std::max(imax, i),
        jmin = std::min(jmin, j), jmax = std::max(jmax, j);
      } else if (a[i][j] != '#') {
        dq.push_back({i, j});
      }
    }
  }

  fin.close();

  if (c == 1) {
    fout << (imax - imin + 1) * (jmax - jmin + 1) << '\n';
    fout.close();
    return 0;
  }

  int l = (int)cuv.size();

  std::vector<int> poz('Z' + 1);
  for (i = 0; i < l; ++i) {
    poz[cuv[i]] = i;
  }

  std::sort(
      dq.begin(), dq.end() + l,
      [&poz](const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
        return poz[a[p1.first][p1.second]] < poz[a[p2.first][p2.second]];
      });

  /// /// /// //// ///

  int dsz = (int)dq.size();
  for (k = 0; k < n; ++k) {
    i = dq[k].first, j = dq[k].second;
    mat[i][j] = k;
  }

  for (i = 0; i < l; ++i) {
    for (k = 0; k < dsz; ++k) {
      for (j = 0; j < l; ++j) {
        cost[i][j][k] = oo;
      }
    }

    cost[i][i][i] = 0;
    q.push(i);
    lee(i, i);
  }

  for (int l = 2; l <=) return 0;
}
