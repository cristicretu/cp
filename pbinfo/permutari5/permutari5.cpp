#include <algorithm>
#include <iostream>

using namespace std;

int n, v[12], st[12], poz;
bool p[12];
int mn = (1 << 30) - 1;

bool valid(int k) {
  if (k == poz && v[st[k]] != mn) return false;

  for (int i = 1; i < k; ++i) {
    if (st[k] == st[i]) return false;
  }

  return true;
}

void bkt(int k) {
  for (int i = 1; i <= n; ++i) {
    if (!p[i]) {
      p[i] = true;
      st[k] = i;
      if (valid(k)) {
        if (k == n) {
          for (int j = 1; j <= n; ++j) {
            cout << v[st[j]] << ' ';
          }
          cout << '\n';
        } else {
          bkt(k + 1);
        }
      }

      p[i] = false;
    }
  }
}

int main(void) {
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
    if (v[i] < mn) {
      mn = v[i];
      poz = i;
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (v[j] != mn) {
        if (v[i] > v[j]) {
          int temp = v[i];
          v[i] = v[j];
          v[j] = temp;
        }
      }
    }
  }

  bkt(1);
};