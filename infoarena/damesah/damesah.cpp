#include <fstream>

std::fstream fin("damesah.in", std::ios::in);
std::fstream fout("damesah.out", std::ios::out);

int n, ans;
int sol[15];

bool col[15], d1[30], d2[30];

void bkt(int k) {
  if (k == n + 1) {
    if (ans < 1) {
      for (int i = 1; i <= n; ++i) {
        fout << sol[i] << ' ';
      }
      fout << '\n';
    }
    ans++;
  } else {
    for (int i = 1; i <= n; ++i) {
      if (!col[i] && !d1[k - i + n] && !d2[k + i - 1]) {
        col[i] = d1[k - i + n] = d2[k + i - 1] = 1;
        sol[k] = i;
        bkt(k + 1);
        col[i] = d1[k - i + n] = d2[k + i - 1] = 0;
      }
    }
  }
}

int main() {
  fin >> n;
  bkt(1);
  fout << ans;
  return 0;
}
