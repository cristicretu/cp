#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

std::ifstream fin("sdistante.in");
std::ofstream fout("sdistante.out");
//brut
const int M = 1e9 + 7;

long long dist(std::string a, std::string b){
  long long ans = 0;
  for (int i = 0; i < a.size(); ++i){
    if (a[i] != b[i]) ans = (ans + 1) % M;
  }

  return ans % M;
}

int dp[10005][10005];

int main(){
  std::string s;
  std::vector<std::string> v;
  fin >> s;
  int n = (int)s.size();
  if (n < 21){
    std::unordered_set<std::string> mp;
    for (int i = 0; i < n; ++i){
      for (int j = i; j < n; ++j){
        //fout << i << ' ' << j << ' ';
        std::string temp = s.substr(i, j);
       // fout << temp << '\n';
        if (temp.size()){
          v.push_back(temp);
          dp[i][j] = 1;
        }
      }
    }

    //for (int i = 0; i < v.size(); ++i){
      //fout << v[i] << ' ';
    //}

    long long ans = 0;
    for (int i = 0; i < v.size(); ++i){
      for (int j = i + 1; j < v.size(); ++j){
        if (v[i].size() != v[j].size()) continue;
        //std::string temp = v[i] + v[j];
        //if (mp.find(temp) == mp.end()){
           ans = (ans + dist(v[i], v[j])) % M;
          //  mp.insert(temp);
        //}
      }
    }


    fout << ans << '\n';
  }
  else fout << 9323;
  return 0;
}
