#include <fstream>

std::fstream fin("combinari.in", std::ios::in);
std::fstream fout("combinari.out", std::ios::out);

int n, c;
int x[20];

void afis(int k) {
  for (int i = 1; i <= k; ++i) {
    fout << x[i] << ' ';
  }
  fout << '\n';
}

bool OK(int k) {
  for (int i = 1; i < k; ++i) {
    if (x[k] == x[i]) return false;
  }

  if (k > 1 && x[k] <= x[k - 1]) return false;
  return true;
}

bool sol(int k) { return k == c; }

void bkt(int k) {
  for (int i = 1; i <= n; ++i) {
    x[k] = i;
    if (OK(k)) {
      if (sol(k)) {
        afis(k);
      } else {
        bkt(k + 1);
      }
    }
  }
}

int main() {
  fin >> n >> c;
  bkt(1);
  return 0;
}
