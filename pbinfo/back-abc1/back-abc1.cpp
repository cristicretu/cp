#include <algorithm>
#include <iostream>

std::string alfa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int n, m;
char sol[30];

bool ok(int k) {
  for (int i = 1; i < k; ++i) {
    if (sol[i] >= sol[k]) return false;
    if (sol[i] < sol[i - 1]) return false;
  }
  return true;
}

void bkt(int k) {
  for (int i = 0; i < n; ++i) {
    sol[k] = alfa[i];

    if (ok(k)) {
      if (k == m) {
        for (int j = 1; j <= m; ++j) {
          std::cout << sol[j];
        }
        std::cout << '\n';
      } else {
        bkt(k + 1);
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> n >> m;
  bkt(1);
  return 0;
}
