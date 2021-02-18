#include <cstring>
#include <fstream>

std::ifstream fin("alinieri.in");

std::ofstream fout("alinieri.out");

long long n, p, z, spd, ans;

int a[1001], nr[190];

int main() {
  fin >> n >> p >> z;

  for (int i = 1; i <= n; ++i) {
    fin >> spd;

    a[spd]++;
  }

  for (int i = 1; i <= 360; ++i) {
    int al = 0;

    memset(nr, 0, sizeof(nr));

    for (int j = 1; j <= 1000; ++j) {
      if (a[j]) {
        nr[(i * j) % 180] += a[j];
      }
    }

    for (int j = 0; j < 180; ++j) {
      if (nr[j] >= p) {
        al++;
      }
    }

    ans += al;
  }

  ans *= (z / 360);

  for (int i = 1; i <= z % 360; ++i) {
    int al = 0;

    memset(nr, 0, sizeof(nr));

    for (int j = 1; j <= 1000; ++j) {
      if (a[j]) {
        nr[(i * j) % 180] += a[j];
      }
    }

    for (int j = 0; j < 180; ++j) {
      if (nr[j] >= p) {
        al++;
      }
    }

    ans += al;
  }

  fout << ans;

  return 0;
}