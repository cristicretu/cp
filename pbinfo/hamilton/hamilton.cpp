#include <iostream>
#include <fstream>

std::fstream fin("hamilton.in", std::ios::in);
std::fstream fout("hamilton.out", std::ios::out);

int n, mat[25][25], ok,  nod[25], viz[25], a, b;

void print(){
  fout << "1\n";
  for (int i = 1; i <= n; ++i){
    fout << nod[i] << ' ';
  }
  fout << nod[1];
  ok = 1;
}

void bkt(int k){
  for (int i = 1; i <= n && !ok; ++i){
    if (!viz[i]){
      viz[i] = 1;
      nod[k] = i;
      if (k == 1 || mat[nod[k - 1]][nod[k]] == 1){
        if (k == n && mat[nod[k]][nod[1]] == 1) print();
        else bkt(k + 1);
      }
      viz[i] = 0;
    }
  }
}

int main(){
	fin >> n;

  while (fin >> a >> b){
    mat[a][b] = mat[b][a] = 1;
  }

  bkt(1);
  if (ok == 0){
    fout << "0";
  }
  return 0;
}
