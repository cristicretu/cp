#include <iostream>

using namespace std;

int n, st[20], v[20];
bool p[20];

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

bool valid(int k) {
  for (int i = 1; i <= n; ++i) {
    if (k == i && ePrim(v[i]) && v[st[k]] != v[i]) return false; 
  }
  return true;
}

void bkt(int k) {
  for (int i = 1; i <= n; ++i) {
    if (!p[i]) {
      p[i] = 1;
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
      p[i] = 0;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (!ePrim(v[j]) && v[i] > v[j]) {
        int aux = v[i];
        v[i] = v[j];
        v[j] = aux;
      }
    }
  }

  bkt(1);
  return 0;
}
