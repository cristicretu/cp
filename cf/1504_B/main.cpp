#include <iostream>


void solve(){
  int n;
  std::string a, b;
  std::cin >> n >> a >> b;
  a.push_back('0'), b.push_back('0');
  int cnt = 0;
  for (int i = 0; i < n; ++i){
    cnt += (a[i] == '1') - (a[i] == '0');
    if ((a[i] == b[i]) != (b[i + 1] == a[i + 1]) && cnt != 0){
      std::cout << "NO\n";
      return;
    }
  }
  std::cout << "YES\n";
}

int main(){
  int t;
  std::cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
