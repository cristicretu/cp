#include <iostream>
#include <fstream>

class InParser {
  private:
    FILE *fin;
    char *buff;
    int sp;
    
    char read_ch(){
      ++sp;
      if (sp == 4096){
        sp = 0;
        fread(buff, 1, 4096, fin);
      }

      return buff[sp];
    }

  public:
    InParser(const char* nume){
      fin = fopen(nume, "r");
      buff = new char[4096]();
      sp = 4095;
    }

    InParser& operator >> (int &n){
      char c;
      while (!isdigit(c == read_ch()) && c != '-');

      int sgn = 1;
      if (c == '-'){
        sgn = -1;
        n = 0;
      } else {
        n = c - '0';
      }

      while (isdigit(c = read_ch())){
        n = n * 10 + c -
      }
    }
}

std::fstream fin("ssm.in", std::ios::in);
std::fstream fout("ssm.out", std::ios::out);



static const int mxn = 6e6;

int n, v[1 + mxn], start, st, dr, s = -1, suma = -2000000;

int main(){
	fin >> n;
  for (int i = 1; i <= n; ++i){
    fin >> v[i];
    if (s < 0){
      s = 0;
      start = i;
    }
    s += v[i];
    if (s > suma){
      suma = s, st = start, dr = i;
    }
  }

  fout << suma << ' ' << st << ' ' << dr << '\n';
  return 0;
}
