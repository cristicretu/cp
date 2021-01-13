#include <stdio.h>
#include <stdlib.h>

int main() {
  char s[1024];
  scanf("%s", &s);

  int n = strlen(s);
  int *fv = (int *)malloc(n * sizeof(int));
  memset(fv, 0, sizeof(fv));

  int i;
  for (i = 0; i < n; ++i) fv[s[i]]++;

  for (i = 0; i < 10; ++i) printf("%d ", fv[i + 48]);
  return 0;
}
