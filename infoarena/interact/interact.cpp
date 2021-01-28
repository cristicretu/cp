
#include <iostream>

std::string s;

bool ok(std::string s) {
  std::cout << "? " << s << std::endl;
  bool n;
  std::cin >> n;
  return n;
}

int main() {
  for (char c = 'a'; c <= 'z'; c++) {
    for (int i = 0; i <= s.size() && s.size() < 100; i++) {
      std::string aux = s;
      aux.insert(i, 1, c);
      if (ok(aux)) s = aux;
    }
  }
  std::cout << "! " << s << std::endl;
  return 0;
}