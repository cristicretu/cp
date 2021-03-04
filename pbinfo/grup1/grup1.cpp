#include <iostream>
#include <fstream>
#include <algorithm>

std::fstream fin("grup1.in", std::ios::in);
std::fstream fout("grup1.out", std::ios::out);

static const int mxn = 1e5;

struct pct{
  int ab;
  bool pt, du;
};

int n, s, k1, k2;
pct v[mxn];

int main(){
	fin >> n >> s >> k1 >> k2;
  for (int i = 0; i < n; ++i){
    fin >> v[i].ab;
  }

  for (int i = 0; i < n; ++i){
    char c;
    fin >> c;
    v[i].pt = ((c == '1') ? 1 : 0);
  }

  for (int i = 0; i < n; ++i){
    char c;
    fin >> c;
    v[i].du = ((c == '1') ? 1 : 0);
  }
  
  std::sort(v, v + n, [](pct a, pct b){
    return a.ab < b.ab;
  });
  
  long long ans = 0;
  int k1temp = 0, k2temp = 0;
  for (int i = 0; i < n; ++i){
    if (v[i].pt == 1){
      if (v[i].du == 1){
        if (k2temp >= k2)
          continue;
        else {
          k2temp ++;
        }
      }

      if (k1temp < k1){
        k1temp++;
        ans += v[i].ab;
      }
    } 
  }

  

  /* for (int i = 0; i < n; ++i){ */
    /* fout << v[i].ab << ' '; */
  /* } */ 
  return 0;
}
