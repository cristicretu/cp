#include <iostream>
#include <fstream>

std::fstream fin("beep.in", std::ios::in);
std::fstream fout("beep.out", std::ios::out);

int main(){
	std::string s, a;
  fin >> a;
  while (fin >> s){
    if (a == s){
      fout << "beep";
    } else { 
      fout << s;
    }
    fout << ' ';
  }
  return 0;
}
