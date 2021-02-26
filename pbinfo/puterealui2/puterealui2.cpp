#include <iostream>
#include <fstream>

inline bool powerof2(int n){
  return (n & (n - 1)) == 0;
}

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;

  std::cout << (powerof2(n) ? "DA" : "NO") << '\n';
  return 0;
}
