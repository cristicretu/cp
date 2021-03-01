#include <iostream>
#include <fstream>
#include <queue>

std::fstream fin("vis.in", std::ios::in);
std::fstream fout("vis.out", std::ios::out);

static const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}, 
             mxn = 1e3;

int n, k1, k2, l1, c1, l2, c2;
int a[1 + mxn][1 + mxn], mat[1 + mxn][1 + mxn];

std::queue<std::pair<int,int>> cords;

inline bool ok(int i, int j){
  return i && j && i <= n && j <= n && mat[i][j] == 0;
}

inline void lee(){
  cords.push({1, 1});
  bool k1activ = false, k2activ = false;
  while (!cords.empty()){
    int i = cords.front().first, j = cords.front().second;
    cords.pop();

    for (int k = 0; k < 4; ++k){
      int ni = i + dx[k], nj = dy[k];
      if (ok(ni, nj)){
        if (k1activ == 1 && k2activ == 1
            && a[ni][nj] <= k1 && a[ni][nj] >= k2 ){
          mat[ni][nj] = 1 + mat[i][j];
          cords.push({ni,nj});
        } else if (k1activ == 1 && a[ni][nj] <= k1){
          mat[ni][nj] = 1 + mat[i][j];
          cords.push({ni,nj});
        } else if (k2activ == 1 && a[nj][nj] >= k2){
          mat[ni][nj] = 1 + mat[i][j];
          cords.push({ni,nj});
        } else {
          mat[ni][nj] = 1 + mat[i][j];
          cords.push({ni,nj});
        }
      }
    }
  }
}
int main(){
	fin >> n >> k1 >> k2 >> l1 >> c1 >> l2 >> c2;
  for (int i = 1; i <= n; ++i){
    for (int j = 1; j <= n; ++j){
      fin >> a[i][j];
    }
  }

  lee();

  std::cerr << mat[n][n];
  fout << mat[n][n] << '\n';
  return 0;
}
