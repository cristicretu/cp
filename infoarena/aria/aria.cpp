#include <bits/stdc++.h>

std::ifstream fin("aria.in");
std::ofstream fout("aria.out");


int main(){
  int n;
  fin >> n;

  std::vector<std::pair<double, double>> v(n);
  for (auto &i : v){
    fin >> i.first >> i.second;
  }
  v.push_back({v[0].first, v[0].second});
  
  double ans = 0;
  for (int i = 0; i < n; ++i){
    ans += v[i].first * v[i + 1].second - v[i + 1].first * v[i].second;
  }

  ans /= 2.0;
  if (ans == (int)ans){
    fout << ans << '\n';
  } else {
    fout << std::fixed << std::setprecision(5) << ans << '\n';
  }

}
