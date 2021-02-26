#include <iostream>
#include <fstream>
#include <algorithm>

std::fstream fin("inv.in", std::ios::in);
std::fstream fout("inv.out", std::ios::out);

static const int M = 9917, mxn = 1e5;

int n, f[1 + mxn];
std::pair<int, int> v[1 + mxn];

int mand(int x){
  return (x & (-x));
}

long long q(int x){
  long long ans(0);
  while (x > 0){
    ans += f[x];
    x -= mand(x);
  }

  return ans;
}

void upd(int x, int val){
  while (x <= n){
    f[x] += val;
    x += mand(x);
  }
}

int main(){
  fin >> n;

  for (int i = 1; i <= n; ++i){
    fin >> v[i].first;
    v[i].second = i;
  }

  std::sort(v + 1, v + n + 1);
  for (int i = 1; i <= n; ++i){
    v[i].first = i;
  }
  std::sort(v + 1, v + n + 1,  [](const std::pair<int, int> a,
      const std::pair<int, int> b){ return a.second < b.second; });

  long long ans(0);
  for (int i = 1; i <= n; ++i){
    ans += q(v[i].first - 1);
    upd(v[i].first, 1);
  }

  fout << (1LL * n * (n - 1) / 2 - 1LL * ans) % M;
  return 0;
}
