#include <iostream>
#include <fstream>

std::fstream fin("medie.in", std::ios::in);
std::fstream fout("medie.out", std::ios::out);

static const int mxn = 9e3, mxfv = 7e3;

int n, v[1 + mxn], fv[1 + mxfv];

int main(){
	fin >> n;
  int mx = 0;
  for (int i = 1; i <= n; ++i){
    fin >> v[i];
    mx = std::max(mx, v[i]);
    ++fv[v[i]];
  }
  int ans = 0;
  for (int i = 1; i <= mx; ++i){
    ans += (fv[i] - 1) * (fv[i] - 2) / 2 * fv[i];
    for (int j = i + 1; j <= mx; ++j){
      if (fv[i] > 0 && fv[j] > 0 && (i + j) % 2 == 0){
        ans += fv[(i + j) / 2] * fv[i] * fv[j];
      }
    }
  }
  fout << ans;
  return 0;
}
