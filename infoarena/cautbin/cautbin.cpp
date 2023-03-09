#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("cautbin.in");
ofstream fout("cautbin.out");

using VI = vector<int>;

unsigned n, m;
VI v;

void read();
void solve();

int main() {
  read();
  solve();
  return 0;
}

void read() {
  fin >> n;
  v = VI(n + 1);
 
  for (unsigned i = 1; i <= n; ++i) {
   fin >> v[i];
  } 
  
  fin >> m;
}


void solve() {
  int op, x;
  while (m--) {
    fin >> op >> x;
    
    int ans = 0;
    if (op == 2) {
      int lb = 1, rb = n;
      
      while (lb <= rb) {
        int mb = lb + (rb - lb) / 2;
        
        if (v[mb] < x) {
          lb = mb + 1;
        } else {
          ans = mb;
          rb = mb - 1;
        }
      }
      
      fout << ans << '\n';
    } else {
      int lb = 1, rb = n;
      
      while (lb <= rb) {
        int mb = lb + (rb - lb) / 2;
        
        if (v[mb] <= x) {
          ans = mb;
          lb = mb + 1;
        } else {
          rb = mb - 1;
        }
      }
      
      if (op == 0) {
        if (v[ans] == x) fout << ans;
        else fout << "-1";
      } else {
        fout << ans;
      }
      fout << '\n';
    }
  }
}