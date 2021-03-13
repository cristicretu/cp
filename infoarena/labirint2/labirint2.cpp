#include <iostream>
#include <fstream>
#include <queue>
#include <bitset>

std::fstream fin("labirint2.in", std::ios::in);
std::fstream fout("labirint2.out", std::ios::out);

static const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1},
                 mxn = 1e3;

int n, m, mat[2][1 + mxn][1 + mxn];
std::bitset<1 + mxn> a[1 + mxn];
std::queue<std::pair<int, int> > cords;

inline bool ok(int i, int j){
  return i && j && i <= n && j <= m;
}

void Lee(int st, int x, int y){
  mat[st][x][y] = 1;
  cords.push({x , y});
  while (!cords.empty()){
    int i = cords.front().first;
    int j = cords.front().second;

    cords.pop();
    for (int k = 0; k < 4; ++k){
      int ni = i + dx[k];
      int nj = j + dy[k];
      if (ok(ni, nj) && mat[st][ni][nj] == 0){
        mat[st][ni][nj] = 1 + mat[st][i][j];
        if (a[ni][nj] == 0){
          cords.push({ni, nj});
        }
      }
    }
  }
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

  Lee(0, 1, 1);
  Lee(1, n, m);

  for (int i = 1; i <= n; ++i, fout << '\n'){
    for (int j = 1; j <= m; ++j){
      if (a[i][j] == 1 && mat[0][i][j] && mat[1][i][j] &&
          (mat[0][i][j] + mat[1][i][j] - 1 < mat[1][1][1])){
        fout << '1';
      } else {
        fout << '0';
      }
    }
  }
  return 0;
}
