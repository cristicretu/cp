#include <iostream>
#include <fstream>

std::fstream fin("cuvinte.in", std::ios::in);
std::fstream fout("cuvinte.out", std::ios::out);

static const int mxn = 200;

int n, k, v[1 + mxn], best[1 + mxn], nr[1 + mxn];

int main(){
	fin >> n >> k;

  for (int i = 1; i <= n; ++i){
    fin >> v[i]; best[i] = nr[i] = 1;
  }

  int mx(0);
  for (int i = n; i; --i){
    for (int j = n; j > i; --j){
      if (v[j] > v[i]){
        if (best[j] + 1 > best[i]){
          best[i] = best[j] + 1;
          nr[i] = nr[j];
        } else if (best[i] == best[j] + 1) {
          nr[i] += nr[j];
        }
      }
    mx = std::max(mx, best[i]);
    }
  }

  int val = mx, j = 1;
  for (int i = 1; i <= val; ++i, --mx){
    for (; j <= n; ++j){
      if (mx == best[j]){
        if (nr[j] < k){
          k -= nr[j];
        } else {
          std::cerr << j;
          fout << j << ' ';
          break;
        }
      }
    }
  }
  return 0;
}
