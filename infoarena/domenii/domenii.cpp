/**
 *    author: etohirse
 *    created: 22.12.2020 19:53:08
 **/
#include <fstream>

std::ifstream fin("domenii.in");
std::ofstream fout("domenii.out");

int fv[27];

int main() {
  int n;
  fin >> n;
  std::string s;
  fin >> s;
  long long cnt(0), nrc(0), ans(0);
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] != '.') {
      nrc += 1;
      fv[s[i] - 'a'] += 1;
      cnt += nrc - fv[s[i] - 'a'];
    } else {
      ans += cnt;
    }
  }
  fout << ans;
  return 0;
}
