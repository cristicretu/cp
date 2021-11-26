#include <algorithm>
#include <fstream>

std::ifstream fin("spectacole.in");
std::ofstream fout("spectacole.out");

struct spectacol {
  int start;
  int finish;
};

bool cmp(spectacol a, spectacol b) { return a.finish < b.finish; }

spectacol a[101]; 
int n;

int main() {
  fin >> n;

  for (int i = 0; i < n; ++i) {
    fin >> a[i].start >> a[i].finish;
  }

  std::sort(a, a + n, cmp);

  int ans = 0, last = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i].start >= last) {
      ++ans;
      last = a[i].finish;
    }
  }

  fout << ans << '\n';

  return 0;
}

