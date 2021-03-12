#include <iostream>
#include <fstream>
#include <queue>
#include <bitset>

std::ifstream fin("labirint.in");
std::ofstream fout("labirint.out");

const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1},
          mxn = 1e3;

int n, m, d0;
std::bitset<1 + mxn> a[1 + mxn];
int dist1[1 + mxn][1 + mxn], dist2[1 + mxn][1 + mxn];

std::queue<std::pair<int,int> > cords;

inline bool ok(int i, int j){
  return i && j && i <= n && j <= m && a[i][j] == 0;
}

inline bool ok1(int i, int j){
  return i && j && i <= n && j <= m;
}

int main(){
  fin >> n >> m;
  for (int i = 1; i <= n; ++i){
    for (int j = 1; j <= m; ++j){
      char c;
      fin >> c;
      a[i][j] = (c - '0');
    }
  }

  
  dist1[1][1] = 1;
  cords.push({1, 1});
  while (!cords.empty()){
    int i = cords.front().first, j = cords.front().second;
    cords.pop();

    for (int k = 0; k < 4; ++k){
      int ni = i + dx[k], nj = j + dy[k];

      if (ok(ni,nj) && dist1[ni][nj] == 0){
        dist1[ni][nj] = 1 + dist1[i][j];
        cords.push({ni,nj});
      }
    }
  }

  d0 = dist1[n][m];
  for (int i = 1; i <= n; ++i){
    for (int j = 1; j <= m; ++j){
      dist1[i][j] = 0;
    }
  }

  dist1[1][1] = 1;
  cords.push({1, 1});
  while (!cords.empty()){
    int i = cords.front().first, j = cords.front().second;
    cords.pop();

    for (int k = 0; k < 4; ++k){
      int ni = i + dx[k], nj = j + dy[k];

      if (ok1(ni,nj) && dist1[ni][nj] == 0){
        dist1[ni][nj] = 1 + dist1[i][j];
        cords.push({ni,nj});
      }
    }
  }

  dist2[n][m] = 1;
  cords.push({n, m});
  while (!cords.empty()){
    int i = cords.front().first, j = cords.front().second;
    cords.pop();

    for (int k = 0; k < 4; ++k){
      int ni = i + dx[k], nj = j + dy[k];

      if (ok1(ni,nj) && dist2[ni][nj] == 0){
        dist2[ni][nj] = 1 + dist2[i][j];
        cords.push({ni,nj});
      }
    }
  }

  for (int i = 1; i <= n; ++i, fout << '\n'){
    for (int j = 1; j <= m; ++j){
      fout << dist1[i][j] << ' ';
    }
  }
  fout << '\n';
  for (int i = 1; i <= n; ++i, fout << '\n'){
    for (int j = 1; j <= m; ++j){
      fout << dist2[i][j] << ' ';
    }
  }
  /* for (int i = 1; i <= n; ++i, fout << '\n'){ */
  /*   for (int j = 1; j <= m; ++j){ */
  /*     if (a[i][j] == 1 && (dist1[i][j] + dist2[i][j] - 1) < d0){ */
  /*       fout << "1"; */
  /*     } else { */
  /*       fout << "0"; */
  /*     } */
  /*   } */
  /* } */
  return 0;
}
