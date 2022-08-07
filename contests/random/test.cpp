/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  Test
 *
 *        Version:  1.0
 *        Created:  06/23/2022 09:34:27
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("test.in");


int secventa(int n) {
  int put = 1;
  
  int ans = n;
  while (n % 100) {
    if (n % 100 == 22) {
      ans = ans - 2 * put;
    }

    put *= 10;

    n /= 10;
  }

  return ans;
}

int a[11][11], n, m;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};


int main() {
  // cout << secventa(202233228);
  // cin >> m >> n;

  int a, previous = 0, target = 0, remains = 0, l = 0, ans = 0;

  while (fin >> a) {
    if (a != previous && l != target + remains) {
      l = 0;
      remains = 0;
    } else if (a != previous) {
      remains += l;
              ans = max(ans, l);

    }
    target = a;
    l += 1;
    previous = a;
  }
        ans = max(ans, l);

  cout << ans;

  // for (int i = 1; i <= m; ++i) {
  //   for (int j = 1; j <= n; ++j) {
  //     cin >> a[i][j];
  //   }
  // }

  // int ans(0);

  // for (int i = 1; i <= m; ++i) {
  //   for (int j = 1; j <= n; ++j) {
  //     int min = 11;
  //     for (int k = 0; k < 4; ++k) {
  //       if (a[i][j] <= a[i + dx[k]][j + dy[k]] && (
  //             i + dx[k] >= 1 && i + dx[k] <= m &&
  //             j + dy[k] >= 1 && j + dy[k] <= n
  //             ))
  //         min = a[i + dx[k]][j + dy[k]];
  //     }
  //     if (min > a[i][j]) ans += (min - a[i][j]), a[i][j] = min;
  //   }
  // }

  // sub 3
  // int x, y;
  // fin >> x >> y;


  // int a, last;
  // int ans(0);
  // while (fin >> a) {
  //   if (a <= y && a >= x && a != last) {
  //     ans += 1;
  //   }
  // }
}
