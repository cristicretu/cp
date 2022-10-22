#include <fstream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

ifstream fin("rj.in");
ofstream fout("rj.out");

const int INF = 0x3f3f3f3f;

using VI = vector<int>;
using PI = pair<int, int>;
using VP = vector<PI>;
using VVP = vector<VP>;
using VB = vector<bool>;

int n, m;
int J, C, R, S;

VVP G;      // graph
VI dj, dr;  // distances for j and r
VB vj, vr;  // visited for j and r

void dijkstra(int x, VI& d);
void dfs(int x, VI& d, VB& v);

int main() {
  int x, y, w;
  while (true) {
    fin >> n;

    if (n == -1) {
      break;
    }
    G = VVP(n + 1);
    vj = vr = VB(n + 1);

    fin >> m;
    fin >> J >> C >> R >> S;

    while(m--) {
      fin >> x >> y >> w;

      G[x].emplace_back(y, w);
      G[y].emplace_back(x, w);
    }

    dijkstra(J, dj);
    dijkstra(R, dr);

    dfs(C, dj, vj);
    dfs(S, dr, vr);

    int ans = INF;
    for (size_t node = 1; node <= n; ++node) {
      if (vj[node] && vr[node] && dj[node] == dr[node] && dr[node] < ans) {
        ans = dr[node];
      }
    }

    if (ans != INF) {
      fout << ans << '\n';
    } else {
      fout << "-1\n";
    }
  }
  return 0;
}

void dijkstra(int x, VI& d) {
  d = VI(n + 1, INF);  
  priority_queue<PI, VP, greater<PI> > Q;

  d[x] = 0;
  Q.emplace(0, x);

  while (!Q.empty()) {
    auto [dx, x] = Q.top();
    Q.pop();

    if (dx > d[x]) {
      continue;
    }

    for (auto [y, w] : G[x]) {
      if (d[y] > d[x] + w) {
        d[y] = d[x] + w;
        Q.emplace(d[y], y);
      }
    }
  }
}

void dfs(int x, VI& d, VB& v) {
  v[x] = true;

  for (auto [y, w]: G[x]) {
    if (v[y] || d[x] != d[y] + w) {
      continue;
    }
    dfs(y, d, v);
  }
}
