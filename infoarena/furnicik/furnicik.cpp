#include <iostream>
#include <fstream>
#include <algorithm>

std::fstream fin("furnicik.in", std::ios::in);
std::fstream fout("furnicik.out", std::ios::out);

#define int long long

static const int mxn = 1e5;

int n, l, t, ans[1 + mxn];

int myabs(int a){
  return (a < 0 ? -a : a);
}

int check(int a){
  a = myabs(a);
  if (a > l) a = 2 * l - a;
  return a;
}

int32_t main(){
	fin >> n >> l >> t;

  for (int i = 1; i <= n; ++i){
    int poz, dir;
    fin >> poz >> dir;

    if (dir == 0){
      poz -= t;
    } else {
      poz += t;
    }

    ans[i] = check(check(poz));
  }

  std::sort(ans + 1, ans + n + 1);
  for (int i = 1; i <= n; ++i){
    fout << ans[i] << ' ';
  }
  return 0;
}
