#include <iostream>
#include <fstream>
#include <vector>

using ll = unsigned long long;
using mat = std::vector<std::vector<ll>>;

std::fstream fin("kfib.in", std::ios::in);
std::fstream fout("kfib.out", std::ios::out);

static const ll M = 666013;
static const ll M2 = (ll) M * M;

ll k;

mat cn(int n, int m){
  return std::vector<std::vector<ll>> (n, std::vector<ll> (m));
}

mat mult(mat &a, mat&b){
  mat c = cn(a.size(), b[0].size());
  for (ll i = 0; i < a.size(); ++i){
    for (ll k = 0; k < b.size(); ++k){
      for (ll j = 0; j < b[0].size(); ++j){
        c[i][j] += a[i][k] * b[k][j];

        if (c[i][j] >= M2){
          c[i][j] -= M2;
        }
      }
    }
  }

  for (ll i = 0; i < a.size(); ++i){
    for (ll j = 0; j < b[0].size(); ++j){
      c[i][j] %= M;
    }
  }
  return c;
}

int main(){
	fin >> k;

  mat r = {{0, 1}};
  mat b = {{0, 1}, {1, 1}};

  while (k){
    if(k & 1){
      r = mult(r, b);
    }
    b = mult(b, b);
    k /= 2;
  }

  fout << r[0][0] << '\n';
  return 0;
}
