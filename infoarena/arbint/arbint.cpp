#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

ifstream fin("arbint.in", std::ios::in);
ofstream fout("arbint.out", std::ios::out);

static const int mxn = 1e5;

size_t n, q;
vector<int> aib;

void build(size_t nod, int a, int b){
  if (a == b) {
    fin >> aib[nod];
    return;
  }

  int mid = (a + b) / 2;

  build(nod * 2, a, mid);
  build(nod * 2 + 1, mid + 1, b);
  aib[nod] = max(aib[nod * 2], aib[nod * 2 + 1]);
}

int query(size_t nod, int st, int dr, int a, int b){
  if (st >= a && dr <= b) {
    return aib[nod];
  }

  int mid = (st + dr) / 2;
  int ans = 0;
  if (mid >= a) {
    ans = max(ans, query(nod * 2, st, mid, a, b));
  }
  if (b > mid) {
    ans = max(ans, query(nod * 2 + 1, mid + 1, dr, a, b));
  }
  
  return ans; 
}

void update(size_t nod, int st, int dr, int poz, int val){
  if (st == dr) {
    aib[nod] = val;
    return;
  }

  int mid = (st + dr) / 2;
  if (mid >= poz) {
    update(nod * 2, st, mid, poz, val);
  } else {
    update(nod * 2 + 1, mid + 1, dr, poz, val);
  }

  aib[nod] = max(aib[nod * 2], aib[nod * 2 + 1]);
  return;
}

int main(){
	fin >> n >> q;
  aib.resize(4 * n);

  build(1, 1, n);

  while (q--){
    int c, a , b;
    fin >> c >> a >> b;
    if (c == 0){
      fout << query(1, 1, n, a, b) << '\n';
    } else {
      update(1, 1, n, a, b);
    }
  }
  return 0;
}
