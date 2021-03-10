#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

std::fstream fin("permutari.in", std::ios::in);
std::fstream fout("permutari.out", std::ios::out);

/* int n, sol[10]; */
/* bool ap[10]; */

/* void afis(){ */
/*   for (int i = 1; i <= n; ++i){ */
/*     fout << sol[i] << ' '; */
/*   } */
/*   fout << '\n'; */
/* } */

/* void bkt(int k){ */
/*   if (k == n + 1){ */
/*     afis(); */
/*   } */
/*   for (int i = 1; i <= n; ++i){ */
/*     if (!ap[i]){ */
/*       sol[k] = i; */
/*       ap[i] = 1; */
/*       bkt(k + 1); */
/*       ap[i] = 0; */
/*     } */
/*   } */
/* } */


/* int main(){ */
/* 	fin >> n; */
/*   bkt(1); */
/*   return 0; */
/* } */
int main(){
  int n;
  fin >> n;
  std::vector<int> v;
  for (int i = 0; i < n; ++i){
    v.emplace_back(i + 1);
  }
  do {
    for (auto i : v){
      fout << i << ' ';
    }
    fout << '\n';
  }while(next_permutation(v.begin(), v.end()));

}
