#include <iostream>
#include <fstream>
#include <vector>

using ll = unsigned long long;
using mat = std::vector<std::vector<ll>>;

std::ifstream fin("pandemia.in");
std::ofstream fout("pandemia.out");

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

int n, a, b, u, v, w, ans1, ans2, ans3, t;

int main(){
  fin >> t;
  while (t--){
    fin >> n >> a >> b >> u >> v >> w;
    for (int i = 0; i <= n - 3; ++i){
      int aux1 = w, aux2 = v;
      w = u - a * w - b * v;
      v = aux1, u = aux2;
    }
    fout << w << ' ' << v << ' ' << u << '\n';
  }
  return 0;
}
