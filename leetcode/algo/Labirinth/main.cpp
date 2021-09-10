#include <iostream>

using namespace std;

const int nmax = 2000;

int n, m; 

unsigned int startX, startY;
unsigned int finalX, finalY;

unsigned int matrix[nmax][nmax];

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

bool inBounds(int i, int j);
void Read();
void Show();
void Solve(int i, int j, int k);

int main() {
    Read();
    Solve(startX, startY, 2);
    return 0;
}

void Read() {
    cin >> n >> m;
    cin >> startX >> startY;
    cin >> finalX >> finalY;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }
}

bool inBounds(int i, int j) {
    if (i > n || i < 0) return false;
    if (j > m || j < 0) return false;

    if (matrix[i][j] == 1 && (i == finalX && j == finalY)) return true;
    
    return false;
}

void Show() {
    for (int i = 0; i < n; ++i, cout << '\n') {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << ' ';
        }
    }

    cout << "\n\n";
}

void Solve(int i, int j, int k) {
    if (i == finalX && j == finalY) {
        Show();
        return;
    } else {
        for (int q = 0; q < 4; ++q) {
            int ni = i + dx[q];
            int nj = j + dy[q];

            if (inBounds(ni, nj)) {
                matrix[ni][nj] = k;
                Solve(ni, nj, k + 1);
                matrix[ni][nj] = 0;
            }
        }
    }
}
