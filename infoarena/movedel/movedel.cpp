#include <bits/stdc++.h>

std::ifstream fin("movedel.in");
std::ofstream fout("movedel.out");

const int mxM = 1e6 + 7;

int n, finals;

void generate() {
  std::vector<bool> ciur(mxM, 0), v(n, 0);
  std::vector<int> prim;

  prim.push_back(2);
  for (int i = 3; i < mxM; i += 2) {
    if (!ciur[i]) {
      prim.push_back(i);
      for (int j = i + i; j < mxM; j += i) ciur[j] = 1;
    }
  }
  std::reverse(prim.begin(), prim.end());

  int i = 0, poz = 0;
  while (i < n) {
    poz += prim.back();
    prim.pop_back();
    poz %= n;
    if (!v[poz]) {
      v[poz] = 1;
      ++i;
      finals = poz;
    }
  }
}

int main() {
  fin >> n;

  generate();

  // srand(time(NULL));
  std::string a(n, 'b'), b(n, 'c');
  b[0] = 'a', a[finals] = 'a';

  fout << a << '\n' << b;

  return 0;
}
