#include <algorithm>
#include <fstream>
#include <unordered_set>
#include <vector>

std::fstream fin("zimeria.in", std::ios::in);
std::fstream fout("zimeria.out", std::ios::out);

static const int mxn = 25e4, pr[] = {1, 12, 144, 1728, 20736};

int n, t;
std::string cod;

int idx[2 + 26], fr[2 + mxn];

int main() {
  fin >> t >> n >> cod;

  for (int i = 0; i < 12; ++i) {
    idx[cod[i] - 'a'] = i;
  }

  for (int i = 1; i <= n; ++i) {
    std::string a;
    fin >> a;

    int cnt(0);
    for (int j = 0; j < 5; ++j) {
      cnt += idx[a[j] - 'a'] * pr[4 - j];
    }
    fr[cnt]++;
  }

  if (t == 1) {
    int cnt(0);
    for (int i = 0; i < mxn; ++i) {
      if (fr[i]) {
        cnt++;
      }
    }

    fout << cnt;
  } else {
    for (int i = 0; i < mxn; ++i) {
      for (int j = 1; j <= fr[i]; ++j) {
        std::string temp = "";

        int aux = i;
        for (int k = 1; k <= 5; ++k) {
          temp += cod[aux % 12];
          aux /= 12;
        }

        std::reverse(temp.begin(), temp.end());
        fout << temp << '\n';
      }
    }
  }
  return 0;
}
