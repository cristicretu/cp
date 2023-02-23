#include <bitset>
#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("ciur.in");
ofstream fout("ciur.out");

const int mxn = 2e6;

bitset<mxn> ciur;
int n;

int main() {
  fin >> n;

  ciur[0] = ciur[1] = 1;
  for (int i = 4; i <= n; i += 2) {
    ciur[i] = 1;
  }

  for (int i = 3; i * i <= n; i += 2) {
    if (ciur[i] == 0) {
      for (int j = i * i; j <= n; j += i + i) {
        ciur[j] = 1;
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (!ciur[i]) ans++;
  }
  fout << ans << '\n';
  return 0;
}