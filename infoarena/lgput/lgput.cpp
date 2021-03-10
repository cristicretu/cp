#include <iostream>
#include <fstream>

using ll = long long;

std::fstream fin("lgput.in", std::ios::in);
std::fstream fout("lgput.out", std::ios::out);

static const ll M = 1999999973;

ll n, p;

ll lgput(ll a, ll b){
  ll rez = 1;
  while (b){
    if (b & 1){
      rez = (rez * a) % M;
    }
    a = (a * a) % M;
    b >>= 1;
  }

  return rez;
}

int main(){
  fin >> n >> p;
  fout << lgput(n, p) << '\n';
  return 0;
}
