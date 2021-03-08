#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

std::fstream fin("munte2.in", std::ios::in);
std::fstream fout("munte2.out", std::ios::out);

static const int mxn = 100;

std::vector<int> ans;
int n, k, l;
std::pair<int, int> v[1 + mxn];

int Distanta(const std::pair<int, int> a, const std::pair<int, int> b){
  return sqrt((b.first - a.first) * (b.first - a.first) + 
              (a.first - b.first) * (a.first - b.first));
}

int main(){
	fin >> n >> k >> l;
  for (int i = 1; i <= n; ++i){
    fin >> v[i].first >> v[i].second;
    for (int j = i - 1; j >= 1; --j){
      bool valabil = 1;
      for (int k = j + 1; k < i; ++k){
        if (verif(v[j], v[i], v[k]) == 1){
          valabil = 0;
          break;
        }
      }
      if (valabil){
        fr[i][i] = 1;
        fr[j][j] = 1;
      }
    }
  }

  ans.push_back(1);
  int lungtotal = 0;
  int i = 2;
  while (i <= n - 1){
    int dist = Distanta(v[i - 1], v[i + 1]);
    if (!(v[i - 1].second < v[i].second 
        && v[i].second < v[i + 1].second) && dist < l){
      lungtotal += dist;
      ans.push_back(i + 1);
      i += 2;
    } else {
      lungtotal += Distanta(v[i - 1], v[i]);
      ans.push_back(i);
      ++i;
    }
  }

  ans.push_back(n);
  std::cerr << ans.size() << ", trebuie : " << k << '\n';
  for (auto i : ans)
      std::cerr << i << ' ';
  return 0;
}
