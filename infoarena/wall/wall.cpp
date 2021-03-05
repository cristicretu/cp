#include <iostream>
#include <fstream>
#include <algorithm>

std::fstream fin("wall.in", std::ios::in);
std::fstream fout("wall.out", std::ios::out);

static const int mxn = 1e5;

int n, z;
std::pair<int, int> a[1 + mxn];

int main(){
  fin >> n >> z;

  int MX = 0;
  for (int i = 1; i <= n; ++i){
    fin >> a[i].first;
    a[i].second = i;

    if (a[i].first < z) MX++;
  }

  fout << MX << '\n';
  std::sort(a + 1, a + n + 1, [](const std::pair<int,int> a,
                               const std::pair<int, int> b){
    return a.first > b.first;
  });

  for (int i = 1; i <= n; ++i){
    if ((i & 1) ^ 1){
      fout << a[i].second << ' ' << 1 << '\n';
    } else {
      fout << a[i].second << ' ' << z << '\n';
    }
  }
  return 0;
}
