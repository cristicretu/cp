#include <iostream>
#include <fstream>

std::fstream fin("scmax.in", std::ios::in);
std::fstream fout("scmax.out", std::ios::out);


static const int mxn = 1e5;
int n, poz, nr, lung;
int v[1 + mxn], best[1 + mxn], lg[1 + mxn], p[1 + mxn];

void afis(int i){
  if (p[i] > 0) afis(p[i]);
  fout << v[i] << ' ';
}

int cauta(int x){
  int lb = 0, rb = nr;
  while (lb <= rb){
    int mb = lb + (rb - lb) / 2;

    if (v[lg[mb]] < x && v[lg[mb + 1]] >= x){
      return mb;
    } else if (v[lg[mb + 1]] < x){
      lb = mb + 1;
    } else {
      rb = mb - 1;
    }
  }
  return nr;
}

int main(){
	fin >> n;
  for (int i = 1; i <= n; ++i){
    fin >> v[i];
  }

  best[1] = lg[1] = 1; 
  lg[0] = 0;
  nr = 1;
  for (int i = 2; i <= n; ++i){
    poz = cauta(v[i]);
    p[i] = lg[poz];
    best[i] = poz + 1;
    lg[poz + 1] = i;
    nr = std::max(nr, poz + 1);
  }

  poz = 0;
  for (int i = 1; i <= n; ++i){
    if (lung < best[i]){
      lung = best[i], poz = i;
    }
  }
  fout << lung << '\n';
  afis(poz);
  return 0;
}
