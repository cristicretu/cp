#include <iostream>
#include <set>
#include <fstream>

std::fstream fin("heapuri.in", std::ios::in);
std::fstream fout("heapuri.out", std::ios::out);

const int mxn = 200005; 

int n, poz[mxn], idx;
std::set<int> heap;

int main(){
  fin >> n;
  int x, a;
  for (int i = 1; i <= n; ++i) {
    fin >> x;

    if (x == 1) {
      fin >> a;
      heap.insert(a);
      poz[++idx] = a;
    } else if (x == 2) {
      fin >> a;
      heap.erase(poz[a]);
    } else {
      fout << *heap.begin() << '\n';
    }
  }
  return 0;
}
