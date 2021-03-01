#include <iostream>
#include <fstream>
#include <queue>
#include <deque>

std::fstream fin("vis.in", std::ios::in);
std::fstream fout("vis.out", std::ios::out);

static const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}, 
             mxn = 1e3;

int n, k1, k2, xa, ya, xb, yb;
int mat[1 + mxn][1 + mxn], dist[2][2][1 + mxn][1 + mxn];
bool viz[2][2][1 + mxn][1 + mxn];

struct pct{
  int pa, pb, x, y;
};

/* inline void lee(){ */
/*   cords.push({1, 1}); */
/*   bool k1activ = false, k2activ = false; */
/*   while (!cords.empty()){ */
/*     int i = cords.front().first, j = cords.front().second; */
/*     cords.pop(); */

/*     for (int k = 0; k < 4; ++k){ */
/*       int ni = i + dx[k], nj = dy[k]; */
/*       if (ok(ni, nj)){ */
/*         if (k1activ == 1 && k2activ == 1 */
/*             && a[ni][nj] <= k1 && a[ni][nj] >= k2 ){ */
/*           mat[ni][nj] = 1 + mat[i][j]; */
/*           cords.push({ni,nj}); */
/*         } else if (k1activ == 1 && a[ni][nj] <= k1){ */
/*           mat[ni][nj] = 1 + mat[i][j]; */
/*           cords.push({ni,nj}); */
/*         } else if (k2activ == 1 && a[nj][nj] >= k2){ */
/*           mat[ni][nj] = 1 + mat[i][j]; */
/*           cords.push({ni,nj}); */
/*         } else { */
/*           mat[ni][nj] = 1 + mat[i][j]; */
/*           cords.push({ni,nj}); */
/*         } */
/*       } */
/*     } */
/*   } */
/* } */

int main(){
  fin >> n >> k1 >> k2 >> xa >> ya >> xb >> yb;
  for (int i = 1; i <= n; ++i){
    for (int j = 1; j <= n; ++j){
      fin >> mat[i][j];
    }
  }

  viz[(xa == 1 && ya == 1)][(xb == 1 && yb == 1)][1][1] = 1;
  std::deque<pct> dq;
  dq.push_back({(xa == 1 && ya == 1), (xb == 1 && yb == 1), 1, 1});
  
  while (!dq.empty()){
    pct nod = dq[0];
    dq.pop_front();

    for (int k = 0; k < 4; ++k){
      int ni = nod.x + dx[k], 
          nj = nod.y + dy[k],
          oka = (ni == xa && nj == ya),
          okb = (ni == xb && nj == yb);

          if (ni == 0 || nj == 0 || ni == n + 1 || nj == n + 1){
            continue;
          }
          if (mat[ni][nj] == 0 || (nod.pa && mat[ni][nj] <= k1)
              || (nod.pb && mat[ni][nj] >= k2)){
            if (!viz[oka | nod.pa][okb | nod.pb][ni][nj]){
             viz[oka | nod.pa][okb | nod.pb][ni][nj] = 1;
             dist[oka | nod.pa][okb | nod.pb][ni][nj] = 1 + 
               dist[nod.pa][nod.pb][nod.x][nod.y];
             dq.push_back({oka | nod.pa, okb | nod.pb, ni, nj});
            }
          }
    }
  }

  int ans = (1 << 20);
  for (int i = 0; i <= 1; ++i){
    for (int j = 0; j <= 1; ++j){
      if (viz[i][j][n][n]){
        ans = std::min(ans, dist[i][j][n][n]);
      }
    }
  }

  std::cerr << ans + 1;
  fout << ans + 1;
  return 0;
}
