#include <fstream>
#include <iostream>

std::fstream fin("tort4.in", std::ios::in);
std::fstream fout("tort4.out", std::ios::out);

static const int mxn = 2e5;

int n, v[1 + mxn], sum, ans;
bool fv[1 + 2 * mxn];

int main() {
  fin >> n;
  for (int i = 1; i <= n; ++i) {
    fin >> v[i];
  }
  for (int i = n; i; --i) {
    sum += v[i];
    fv[sum] = 1;
  }
  for (int i = 1; i < sum; ++i) {
    for (int j = i; j < sum && fv[j]; j += i) {
      ans++;
    }
  }
  fout << ans << '\n';
  return 0;
}
