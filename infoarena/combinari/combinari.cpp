#include <iostream>
#include <fstream>

std::fstream fin("combinari.in", std::ios::in);
std::fstream fout("combinari.out", std::ios::out);

int n, k;
int sol[20];

bool ok(int poz){
  for (int i = 1; i < poz; ++i){
    if (sol[i] == sol[poz] || sol[i] > sol[i + 1]) return false;
  }
  return true;
}

void bkt(int poz){
  if (poz == n + 1){
    for (int i = 1; i <= n; ++i){
      fout << sol[i] << ' ';
    }
    fout << '\n';
    return;
  }
  for (int i = 1; i <= k; ++i){
    sol[poz] = i;
    if (ok(poz)) bkt(poz + 1);
  }
}

int main(){
	fin >> k >> n;
  bkt(1);
  return 0;
}
