#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

#define nl '\n'

std::fstream fin("prieteni.in", std::ios::in);
std::fstream fout("prieteni.out", std::ios::out);

int main(){
  int n, ans = 0;
  fin >> n;
  int v[n + 1];
  for (int i = 1; i <= n; ++i){
    fin >> v[i];
  }

  std::sort(v + 1, v + n + 1);
  while (n){
    if (n == 1){
      fout << v[1] << nl << ans + v[1];
    } else if (n == 2) {
      fout << v[1] << ' ' << v[2] << nl << ans + v[2];
    } else if (n == 3) {
      fout << v[1] << ' ' << v[2] << nl << v[1] << nl << v[1] << ' ' << v[3] << nl;
      fout << ans + v[1] + v[2] + v[3];
    } else {
      int x = v[1] * 2 + v[n] + v[n - 1];
      int y = v[1] + v[2] * 2 + v[n];
      if (x < y){
        fout << v[1] <<  ' ' << v[n] << nl << v[1] << nl << v[1] << ' ' << v[n - 1] << nl << v[1] << nl;
      } else {
        fout << v[1] << ' ' << v[2] << nl << v[2] << nl << v[n - 1] << ' ' << v[n] << nl << v[1] << nl;
      }
      ans += std::min(x, y);
    }
    if (n <= 3) n = 0;
    else n -= 2;
  }
  return 0;
}
