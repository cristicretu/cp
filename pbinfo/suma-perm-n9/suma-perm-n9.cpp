#include <iostream>

int n, sol[10], s;
std::string pala;

bool ok(int k) {
  for (int i = 1; i < k; ++i) {
    if (sol[k] == sol[i]) return false;
  }
  return true;
}

int katasol() {
  int cif = 0;
  for (int i = 1; i <= pala.size(); ++i) {
    cif = cif * 10 + sol[i];
  }
  return cif;
}

void bkt(int k) {
  for (int i = 1; i <= pala.size(); ++i) {
    sol[k] = pala[i - 1] - '0';

    if (ok(k)) {
      if (k == pala.size()) {
        s += katasol();
      } else
        bkt(k + 1);
    }
  }
}

int sum(int n) {
  int s = 0;
  while (n) {
    s += n % 10;
    n /= 10;
  }
  return s;
}

int main(void) {
  std::cin >> n;
  pala = std::to_string(n);
  int fact[10];
  fact[0] = fact[1] = 1;

  for (int i = 2; i <= 9; ++i) {
    fact[i] = fact[i - 1] * i;
  }

  std::string suk = "";
  for (int i = 1; i <= pala.size(); ++i) {
    suk[i - 1] = '1';
  }

  std::cout << fact[pala.size() - 1] * sum(n) * std::stoi(suk);
}  // 111…1 * (nrcifre-1)! * sumacifrelor.
