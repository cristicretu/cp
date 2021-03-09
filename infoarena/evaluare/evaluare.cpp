#include <iostream>
#include <fstream>

std::fstream fin("evaluare.in", std::ios::in);
std::fstream fout("evaluare.out", std::ios::out);

std::string s;
int i;

int eval();
int eval1();
int eval2();

int eval(){
  int rez = eval1();
  while (s[i] == '+' || s[i] == '-'){
    if (s[i] == '+'){
      ++i;
      rez += eval1();
    } else {
      ++i;
      rez -= eval1();
    }
  }

  return rez;
}

int eval1(){
  int rez = eval2();
  while (s[i] == '*' || s[i] == '/'){
    if (s[i] == '*'){
      ++i;
      rez *= eval2();
    } else {
      ++i;
      rez /= eval2();
    }
  }

  return rez;
}

int eval2(){
  int rez = 0;
  if (s[i] == '('){
    ++i;
    rez = eval();
    ++i;
  } else {
    while (isdigit(s[i])){
      rez = rez * 10 + (s[i] - '0');
      ++i;
    }
  }

  return rez;
}

int main(){
  fin >> s;
  fout << eval();
  return 0;
}
