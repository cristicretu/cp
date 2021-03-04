#include <iostream>
#include <fstream>

#define int long long

std::fstream fin("costperm.in", std::ios::in);
std::fstream fout("costperm.out", std::ios::out);

static const int mxn = 1e5;

int n, aib[mxn], ans;

void upd(int x){
  for (int i = x; i <= n; i += i & -i){
    ++aib[i];
  }
}

int query(int x){
  int s = 0;
  for (int i = x; i > 0; i -= i & -i){
    s += aib[i];
  }

  return s;
}

int32_t main(){
	fin >> n;
  for (int i = 0; i < n; ++i){
    int x;
    fin >> x;
    ans += x * (i - query(x));
    upd(x);
  }

  std::cerr<<ans;
  fout << ans;
  return 0;
}
