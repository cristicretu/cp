#include <iostream>
#include <fstream>
#include <algorithm>

typedef unsigned long long i64;

i64 p, a, b , c;

i64 check(i64 x){
  i64 y = p % x;
  if (y == 0) return 0ll;
  return x - y;
}

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int t;
  std::cin >> t;
  while (t--){
    std::cin >> p >> a >> b >> c;
  
    std::cout << std::min({check(a), check(b), check(c)}) << '\n';
  }
  return 0;
}
