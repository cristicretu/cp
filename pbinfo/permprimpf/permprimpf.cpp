#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, st[16], a[16];
bool viz[16];

vector<vector<int>> L;

bool ePrim(int x) {
  if (x < 2) return false;
  if (x == 2) return true;
  if (x == 3) return true;
  if (x == 4) return false;
  if (x == 5) return true;
  if (x == 6) return false;
  if (x == 7) return true;
  if (x == 8) return false;
  if (x == 9) return false;
  if (x == 10) return false;
  if (x == 11) return true;
  if (x == 12) return false;
  if (x == 13) return true;
  if (x == 14) return false;
  if (x == 15) return false;
  if (x == 16) return false;
}

bool verif(int k) {
  for (int i = 1; i < k; ++i) {
    if (st[i] == st[k]) return false;
  }
  return true;
}

int idx = 0;

void bkt(int k) {
  if (k == n + 1) {
    for (int i = 1; i <= n; ++i) {
      // L[idx].push_back(a[st[i]]);
    }
    idx++;
  } else {
    if (st[k] && viz[k]) {
      bkt(k + 1);
    } else {
      for (int i = 1; i <= n; ++i) {
        st[k] = i;
        if (verif(k)) {
          bkt(k + 1);
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (ePrim(a[i])) {
      st[i] = i;
      viz[i] = true;
    }
  }

  bkt(1);
  for (int i = 0; i < L.size(); ++i, cout << '\n') {
    for (int j = 0; j < L[0].size(); ++j) {
      cout << L[i][j] << ' ';
    }
  }
  return 0;
}
