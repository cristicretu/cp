#include <algorithm>
#include <iostream>

int n, c;
int a[30], x[30], cnt;
bool viz[30];

void afis() {
  for (int i = 1; i <= c; ++i) {
    printf("%d", a[x[i]]);
  }
  printf("\n");
}

void bkt(int k) {
  for (int i = 1; i <= cnt; ++i) {
    if (!viz[i]) {
      viz[i] = 1;
      x[k] = i;
      if (k == 1 && a[i] == 0)
        ;
      else {
        if (k == c)
          afis();
        else
          bkt(k + 1);
      }
      viz[i] = 0;
    }
  }
}

int main() {
  scanf("%d%d", &n, &c);

  while (n) {
    a[++cnt] = n % 10;
    n /= 10;
  }

  std::sort(a + 1, a + cnt + 1);
  bkt(1);
  return 0;
}
