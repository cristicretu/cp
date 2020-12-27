/**
 *    author: etohirse
 *    created: 27.12.2020 12:09:21
 **/
#include <bits/stdc++.h>

typedef long long ll;

class InParser {
 private:
  std::vector<char> str;
  int ptr;
  std::ifstream fin;
  char getChar() {
    if (ptr == (int)str.size()) {
      fin.read(str.data(), str.size());
      ptr = 0;
    }
    return str[ptr++];
  }
  template <class T>
  T getInt() {
    char chr = getChar();
    while (!isdigit(chr) && chr != '-') chr = getChar();
    int sgn = +1;
    if (chr == '-') {
      sgn = -1;
      chr = getChar();
    }
    T num = 0;
    while (isdigit(chr)) {
      num = num * 10 + chr - '0';
      chr = getChar();
    }
    return sgn * num;
  }

 public:
  InParser(const char* name) : str(1e5), ptr(str.size()), fin(name) {}
  ~InParser() { fin.close(); }
  template <class T>
  friend InParser& operator>>(InParser& in, T& num) {
    num = in.getInt<T>();
    return in;
  }
};

InParser fin("rmq.in");
std::ofstream fout("rmq.out");

const int mxn = 1e6 + 2;
int n, q;
ll x[mxn];

struct node {
  ll mn;
} st[1 << 19];

void upd(int l1, int x, int i = 1, int l2 = 0, int r2 = n - 1) {
  if (l2 == r2) {
    st[i].mn = x;
    return;
  }
  int m2 = (l2 + r2) / 2;
  if (l1 <= m2)
    upd(l1, x, 2 * i, l2, m2);
  else
    upd(l1, x, 2 * i + 1, m2 + 1, r2);
  st[i].mn = std::min(st[2 * i].mn, st[2 * i + 1].mn);
}

int qry(int l1, int r1, int i = 1, int l2 = 0, int r2 = n - 1) {
  if (l1 <= l2 and r2 <= r1) {
    return st[i].mn;
  }
  int m2 = (l2 + r2) / 2;
  return std::min(l1 <= m2 ? qry(l1, r1, 2 * i, l2, m2) : (int)1e9,
                  m2 < r1 ? qry(l1, r1, 2 * i + 1, m2 + 1, r2) : (int)1e9);
}

int main() {
  fin >> n >> q;
  for (int i = 0; i < n; ++i) fin >> x[i], upd(i, x[i]);
  while (q--) {
    int a, b;
    fin >> a >> b;
    --a, --b;
    fout << qry(a, b) << '\n';
  }
  return 0;
}
