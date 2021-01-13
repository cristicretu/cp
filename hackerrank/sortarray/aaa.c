#include <stdio.h>
#include <stdlib.h>

int lexicographic_sort(const char* a, const char* b) {}

int lexicographic_sort_reverse(const char* a, const char* b) {}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {}

int sort_by_length(const char* a, const char* b) {}

void string_sort(char** arr, const int len,
                 int (*cmp_func)(const char* a, const char* b)) {}

int main() {
  int n;
  char s[50][2500];
  scanf("%d", &n);

  int i;
  for (i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }

  return 0;
}
