#include <iostream>
#include <fstream>

std::fstream fin("submultimi.in", std::ios::in);
std::fstream fout("submultimi.out", std::ios::out);

int n, sol[20], t;

void bkt(int k){
  if (k == t + 1){
    for (int i = 1; i <= t; ++i){
      fout << sol[i] << ' ';
    }
    fout << '\n';
    return;
  }
  for (int i = 1 + sol[k - 1]; i <= n - t + k; ++i){
    sol[k] = i;
    bkt(k + 1);
  }
}

int main(){
	fin >> n;
  for (t = 1; t <= n; ++t) bkt(1);
  return 0;
}
