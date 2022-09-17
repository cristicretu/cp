/*
 royfloyd
 shortest path in a weighted, directed graph from x to y using n nodes
 subproblem: -||- using k nodes
 base case dist[u][v] = weight(u,v) (direct link)
          dist[u][u] = 0
  otherwise dist[u][?] = INF

  recursive formula = 
    ans(i,j,k) = min(ans(i, j, k-1), ans(i, k, k - 1) + ans(k, j, k - 1))
*/
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

ifstream fin("royfloyd.in");
ofstream fout("royfloyd.out");

using ll = long long;
#define mod 1000000007
#define INF 0x3f3f3f3f

const int maxn = 101;
int n;
int mat[maxn][maxn];

void solve();
void read();
void royfloyd();

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);


  ll test=1;
  //cin>>test;

  while(test--)
  {
    solve();
  }

  return 0;
}

void royfloyd() {
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (i != j && j != k && k != i &&
            mat[i][j] > mat[i][k] + mat[k][j])
        mat[i][j] = mat[i][k] + mat[k][j];
      }
    }
  }
}

void solve() {
  read();
  royfloyd();

  for (int i = 1; i <= n; ++i, fout << '\n') {
    for (int j = 1; j <= n; ++j) {
      if (mat[i][j] == INF) fout << "0 ";
      else fout << mat[i][j] << ' ';
    }
  }
}

void read() {
  fin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      fin >> mat[i][j];
      if (mat[i][j] == 0) mat[i][j] = INF;
    }
  }
}
