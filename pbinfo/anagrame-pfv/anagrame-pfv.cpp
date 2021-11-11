#include <cstring>
#include <iostream>

char s[12];
char vocale[] = "aeiou";

int n, st[12], p[12];

void afis() {
  for (int i = 1; i <= n; ++i) {
    std::cout << s[st[i]];
  }
  std::cout << '\n';
}

bool valid(int k) {
  if (strchr("aeiou", s[st[k]]) && st[k] != k - 1) return false;
  return true;
}

void bkt(int k) {
  for (int i = 0; i < n; ++i) {
    if (!p[i]) {
      st[k] = i;
      p[i] = 1;
      if (valid(k)) {
        if (k == n) {
          afis();
        } else {
          bkt(k + 1);
        }
      }

      p[i] = 0;
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> s;
  n = strlen(s);

  for (int i = 0; i < n; ++i) {
    if (strchr(vocale, s[i]) == 0) {
      for (int j = i + 1; j < n; ++j) {
        if (strchr(vocale, s[j]) == 0) {
          if (s[i] > s[j]) {
            char aux = s[i];
            s[i] = s[j];
            s[j] = aux;
          }
        }
      }
    }
  }

  bkt(1);

  return 0;
}
