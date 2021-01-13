#include <stdio.h>

int suma(int n) {
  int ans = 0;
  while (n) {
    ans += n % 10;
    n /= 10;
  }
  return ans;
}

int main() {
  freopen("div3.in", "r", stdin);
  freopen("div3.out", "w", stdout);

  int n;
  scanf("%d", &n);
  int *arr = (int *)malloc(n * sizeof(int));

  int i;
  for (i = 0; i < n; ++i) scanf("%d", &arr[i]);

  fclose(stdin);
  for (i = 0; i < n; ++i)
    if (suma(arr[i]) % 3 == 0) printf("%d ", arr[i]);
  fclose(stdout);
  return 0;
}