#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

std::fstream fin("economie.in", std::ios::in);
std::fstream fout("economie.out", std::ios::out);

static const int mxn = 5e4, mxx = 1e3;

int n, v[1 + mxx];
std::vector<int> ans;
bool viz[1 + mxn];

int main(){
	fin >> n;
  for (int i = 1; i <= n; ++i){
    fin >> v[i];
  }
  std::sort(v + 1, v + n + 1);
  for (int i = 1; i <= n; ++i){
    if (!viz[v[i]]){
      viz[v[i]] = 1;
      ans.push_back(v[i]);
      for (int j = 1; j + v[i] <= mxn; ++j){
        if (viz[j]){
          viz[j + v[i]] = 1;
        }
      }
    }
  }

  std::cerr << ans.size();
  fout << ans.size() << '\n';
  for (auto i : ans) fout << i << '\n';
  return 0;
}
