#include <iostream>
#include <bitset>
#include <fstream>

std::fstream fin("ssnd.in", std::ios::in);
std::fstream fout("ssnd.out", std::ios::out);

static const int mxn = 1e6, M = 9973;

long long n;
int t, x, primes[1 + mxn];

std::bitset< 5 + mxn> ciur;

int lgput(int a, int b){
  int rez = 1;
  while (b){
    if (b & 1){
      rez = (rez * a) % M;
    }
    a = (a * a) % M;
    b /= 2;
  }

  return rez;
}

void solve(){
  fin >> n;

  int nd = 1, sd = 1;
  for (int i = 1; i <= x && 1LL * primes[i] * primes[i] <= n; ++i){
    if (n % primes[i]) continue;

    int p = 0;
    while (n % primes[i] == 0){
      ++p;
      n /= primes[i];
    }

    nd *= (p + 1);

    int p1 = (lgput(primes[i], p + 1) - 1) % M;
    int p2 = lgput(primes[i] - 1, M - 2) % M;

    sd = (((sd * p1) % M) * p2) % M;
  }

  if (n > 1){
    nd *= 2;
    sd = (1LL * sd * (n + 1) % M);
  }

  fout << nd << ' ' << sd << '\n';
}

int main(){
  for (int i = 2; i <= mxn; ++i){
    if (ciur[i] == 0){
      primes[++x] = i;
      for (int j = i + i; j <= mxn; j += i){
        ciur[j] = 1;
      }
    }
  }


  int t;
  fin >> t;
  while (t--){
    solve();
  }
  return 0;
}
