#include <iostream>
#include <fstream>

std::fstream fin("palindrom2.in", std::ios::in);
std::fstream fout("palindrom2.out", std::ios::out);

std::string s;

inline bool ok(int i, int n){
  while (i <= n){
    if (s[i] != s[n]) return 1;
    i++; n--;
  }
  return 0;
}

int main(){
  fin >> s;

  fout << s;
  int i, n((int)s.size() - 1);
  for (i = 0; i <= n && ok(i, n); ++i);
  std::cerr << i;
  for (int j = i - 1; j >= 0; --j){
    fout << s[j];
  }
  return 0;
}
