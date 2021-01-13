#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int a, b;
  float c, d;
  scanf("%d %d %f %f", &a, &b, &c, &d);
  printf("%d %d\n%.1f %.1f", a + b, a - b, c + d, c - d);

  return 0;
}
