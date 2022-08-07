/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  no. of ways to go from 0 to n
 *
 *        Version:  1.0
 *        Created:  08/07/2022 14:35:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;

int n;
int ans[100];

int main() {
  cin >> n;

  ans[0] = 1;

  // pull solution
  // ans[1] = 1;

  // for (int i = 2; i <= n; ++i) {
  //  ans[i] = ans[i - 1] + ans[i - 2];
  // }
  
  // push solution
   for (int i = 0; i < n; ++i) {
     if (i + 1 <= n) ans[i + 1] += ans[i];
     if (i + 2 <= n) ans[i + 2] += ans[i];
   }

  cout << ans[n];
}
