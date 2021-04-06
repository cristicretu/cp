#include <iostream>

bool isnotpalin(std::string s){
  int n = s.size();
  for (unsigned i = 0; i < n/2; ++i){
    if (s[i] != s[n - i - 1]) return true;
  }
  return false;
}

int main(){
  int t;
  std::cin >> t;
  while(t--){
    std::string s;
    std::cin >> s;
    if (isnotpalin(s + 'a')){
      std::cout <<"Yes\n" << s + 'a' << '\n';
    } else if (isnotpalin('a' + s)){
      std::cout << "Yes\n" << 'a' + s << '\n';
    } else {
      std::cout << "NO\n";
    }
  }
}
