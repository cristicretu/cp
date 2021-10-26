#include <iostream>
#include <queue>

const int mxn = 1000;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m;
char a[mxn + 1][mxn + 1];
int mat[mxn + 1][mxn + 1];
std::queue<std::pair<int, int> > cords;

int startx, starty, finishx, finishy;
bool ok;
std::string path;

inline bool inBounds(int i, int j) {
  return i && j && i <= n && j <= m && mat[i][j] == 0 && a[i][j] != '#';
}

inline void lee() {
  cords.push(std::make_pair(startx, starty));
  mat[startx][starty] = 1;

  while (!cords.empty()) {
    int i = cords.front().first;
    int j = cords.front().second;

    cords.pop();
    for (int k = 0; k < 4; ++k) {
      int ni = i + dx[k];
      int nj = j + dy[k];

      if (inBounds(ni, nj)) {
        mat[ni][nj] = 1 + mat[i][j];
        cords.push(std::make_pair(ni, nj));
      }
    }
  }
}

int main(void) {
  std::cin >> n >> m;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      std::cin >> a[i][j];

      if (a[i][j] == 'A') {
        startx = i, starty = j;
      } else if (a[i][j] == 'B') {
        finishx = i, finishy = j;
      }
    }
  }

  lee();

  if (mat[finishx][finishy]) {
    std::cout << "YES\n";

    std::cout << mat[finishx][finishy] - 1 << '\n';

    int i = startx, j = starty;
    while (mat[i][j] != mat[finishx][finishy]) {
      int current = mat[i][j] + 1;

      if (mat[i + 1][j] == current) {
        std::cout << "D";
        i++;
      } else if (mat[i][j - 1] == current) {
        std::cout << "L";
        j--;
      } else if (mat[i][j + 1] == current) {
        std::cout << "R";
        j++;
      } else if (mat[i - 1][j] == current) {
        std::cout << "U";
        i--;
      }
    }
  } else {
    std::cout << "NO\n";
  }
}