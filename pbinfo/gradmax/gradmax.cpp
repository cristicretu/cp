#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

std::fstream fin("gradmax.in", std::ios::in);
std::fstream fout("gradmax.out", std::ios::out);

int n, a, b, mat[105][105];
std::pair<int, int> v[105];

int main(){
	fin >> n;
  while (fin >> a >> b){
    mat[a][b] = mat[b][a] = 1; 
  }

  for (int i = 1; i <= n; ++i){
    v[i].first = i;
    for (int j = 1; j <= n; ++j){
      v[i].second += mat[i][j];
    }
  }
  std::sort(v + 1, v + n + 1, []
    (const std::pair<int, int> a, const std::pair<int, int> b){
    return a.second < b.second;
  });

  std::vector<int> vec;
  for (int i = n; i && v[i].second >= v[n].second; --i){
    vec.push_back(v[i].first);
  }

  std::reverse(vec.begin(), vec.end());
  fout << vec.size() << ' ';
  for (auto i : vec){
    fout << i << ' ';
  }
  return 0;
}
