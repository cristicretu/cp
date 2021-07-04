#include <fstream>
#include <iostream>
#include <vector>
#include <queue>

std::ifstream fin("test.in");
std::ofstream fout("test.out");

const int mxN = 1e3;

const int dx[4] = {-1, 0, 1, 0}, 
          dy[4] = {0, 1, 0, -1};

int n, mat[mxN + 1][mxN + 1], ans[mxN + 1][mxN + 1];
bool viz[mxN + 1][mxN + 1];

void dfs(int x, int y);

int main()
{
    fin >> n; 
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            fin >> mat[i][j];
        }
    }
    
    for (int i = 1; i <= n; ++i)
    {
        if (mat[1][i] == 1 && viz[1][i] == 0)
        {
            dfs(1, i);
        }

        if (mat[i][n] == 1 && viz[i][n] == 0)
        {
            dfs(i, n);
        }
        
        if (mat[n][i] == 1 && viz[n][i] == 0)
        {
            dfs(n, i);
        }

        if (mat[i][1] == 1 && viz[i][1] == 0)
        {
            dfs(i, 1);
        }
    }

    for (int i = 1; i <= n; ++i, fout << '\n')
    {
        for (int j = 1; j <= n; ++j)
        {
            fout << ans[i][j] << ' ';
        }
    }
    return 0;
}

bool good(int i, int j)
{
    return i > 0 && j > 0 && i <= n && j <= n;
}

void dfs(int x, int y)
{
    viz[x][y] = 1;
    ans[x][y] = 1;
    std::queue<std::pair<int, int>> cords;

    cords.push({x, y});

    while (!cords.empty())
    {
        int i = cords.front().first;
        int j = cords.front().second;

        cords.pop();
        for (int k = 0; k < 4; ++k)
        {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (viz[ni][nj] == 0 && good(ni, nj) && mat[ni][nj] == 1)
            {
                ans[ni][nj] = 1;
                viz[ni][nj] = 1;

                cords.push({ni, nj});
            }
        }
    }
}
