#include <bits/stdc++.h>

std::ifstream fin("sah.in");
class OutParser {
#pragma warning(disable : 4996)
 private:
  FILE* fout;
  char* buff;
  int sp;
  void write_ch(char ch) {
    if (sp == 50000) {
      fwrite(buff, 1, 50000, fout);
      sp = 0;
      buff[sp++] = ch;
    } else
      buff[sp++] = ch;
  }

 public:
  OutParser(const char* name) {
    fout = fopen(name, "w");
    buff = new char[50000]();
    sp = 0;
  }
  ~OutParser() {
    fwrite(buff, 1, sp, fout);
    fclose(fout);
  }
  OutParser& operator<<(int vu32) {
    if (vu32 <= 9)
      write_ch(vu32 + '0');
    else {
      (*this) << (vu32 / 10);
      write_ch(vu32 % 10 + '0');
    }
    return *this;
  }
  OutParser& operator<<(char ch) {
    write_ch(ch);
    return *this;
  }
  OutParser& operator<<(const char* ch) {
    while (*ch) {
      write_ch(*ch);
      ++ch;
    }
    return *this;
  }
};

OutParser fout("sah.out");

int main() {
  int n, half;
  fin >> n;
  half = n / 2;

  for (int i = 0; i < n; ++i, fout << '\n') {
    int x = i / 2;
    for (int j = 0; j < n; ++j) fout << (n - x > j ? x + 1 : half + x) << ' ';
  }
  return 0;
}
