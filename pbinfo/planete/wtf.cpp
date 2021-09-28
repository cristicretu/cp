#include <iostream>
#include <set>
#include <vector>

const int maxN = 200000;

int n;
int mat[1 + maxN];
int fr[1 + maxN];

int main(void) {
  int i;
  scanf("%d", &n);

  for (i = 1; i <= n; ++i) {
    scanf("%d", &mat[i]);
  }

  int ans = 0;
  for (i = 1; i <= n; ++i) {
    fr[i] += 1;
    int vecin = mat[i];
    ans = 1;

    while (fr[vecin] + 1 <= i) {
      ans += 1;
      fr[vecin] += 1;
      vecin = mat[vecin];
    }

    printf("%d ", ans);

    // printf("%d ", s.size());
  }

  printf("\n");
  return 0;
}