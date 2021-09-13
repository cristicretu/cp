#include <iostream>
#include <set>
#include <fstream>

std::fstream fin("heapuri.in", std::ios::in);
std::fstream fout("heapuri.out", std::ios::out);

const int mxn = 10000;

int n, poz[2 * mxn + 5], idx;
std::set<int> heap;

int main(){
  fin >> n;
  for (int i = 1; i <= n; ++i) {
    int x;
    fin >> x;

    if (x == 1) {
      int a;
      fin >> a;
      heap.insert(a);
      poz[++idx] = a;
    } else if (x == 2) {
      int a;
      fin >> a;
      heap.erase(poz[a]);
    } else {
      fout << *heap.begin() << '\n';
    }
  }
  return 0;
}
