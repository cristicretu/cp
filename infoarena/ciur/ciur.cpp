#include <iostream>
#include <bitset>
#include <fstream>

std::fstream fin("ciur.in", std::ios::in);
std::fstream fout("ciur.out", std::ios::out);

static const int mxn = 2e6;

std::bitset<mxn> ciur;
int n;

int main(){
	fin >> n;
  fin.close();
  for (int i = 4; i <= n; i += 2)
    ciur[i] = true;
  for (int i = 3; i * i <= n; i += 2){
    if (ciur[i] == false){
      for (int j = i * i; j <= n; j += i + i)
        ciur[j] = true;
    }
  }
  ciur[1] = ciur[0] = true;

  int ans = 0;
  for (int i = 1; i <= n; ++i){
    if (!ciur[i]) ans++;
  }
  fout << ans << '\n';
  fout.close();
  return 0;
}
