#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

std::fstream fin("cafea.in", std::ios::in);
std::fstream fout("cafea.out", std::ios::out);

int k, s, n;

int main(){
	fin >> k >> s >> n;

  std::vector<std::pair<int, double> > v(n);
  for (int i = 0; i < n; ++i){
    int x;
    fin >> v[i].first >> x;
    v[i].second = (double) x / v[i].first;
  }
  std::sort(v.begin(), v.end(),
      [](std::pair<int, double> a, std::pair<int, double> b){
      return a.second < b.second;    
  });

  /* for (auto i : v){ */
  /*   std::cerr << i.first << ' ' << i.second << '\n'; */
  /* } */

  int i = 0;
  while (k > 0){
    if (k > v[i].first){
      k -= v[i].first, s -= (int) v[i].first * v[i].second;
      ++i;
    } else {
      s -= (int) k * v[i].second;
      k = 0;
    }
  }

  fout << s << '\n';
  return 0;
}
