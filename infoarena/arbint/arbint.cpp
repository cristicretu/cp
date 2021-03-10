#include <iostream>
#include <fstream>

std::fstream fin("arbint.in", std::ios::in);
std::fstream fout("arbint.out", std::ios::out);

static const int mxn = 1e5;

int n, v[1 + mxn], q , aib[1 + 4 * mxn];

void build(int nod, int a, int b){
  if (a == b){
    aib[nod] = v[a];
    return;
  }

  int mb = (a + b) / 2;
  build(nod * 2, a, mb);
  build(nod * 2 + 1, mb + 1, b);
  aib[nod] = std::max(aib[nod * 2], aib[nod * 2 + 1]);
  return;
}

int query(int nod, int st, int dr, int a, int b){
  if (st >= a && dr <= b){
    return aib[nod];
  }

  int mb = (st + dr) / 2, rez = 0;
  if (mb >= a){
    rez = std::max(rez, query(nod * 2, st, mb, a, b));
  }
  if (mb + 1 <= b){
    rez = std::max(rez, query(nod * 2 + 1, mb + 1, dr, a, b));
  }
  return rez;
}
void update(int nod, int st, int dr, int poz, int val){
  if (st == dr){
    aib[nod] = val;
    return;
  }

  int mb = (st + dr) / 2;
  if (mb >= poz){
    update(nod * 2, st, mb, poz, val);
  } else {
    update(nod * 2 + 1, mb + 1, dr, poz, val);
  }
  aib[nod] = std::max(aib[nod * 2], aib[nod * 2 + 1]);
  return;
}

int main(){
	fin >> n >> q;
  for (int i = 1; i <= n; ++i){
    fin >> v[i];
  }
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
