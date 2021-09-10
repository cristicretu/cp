#include <iostream>

const int maxn = 1e5;

int temp[maxn];
void mergeSort(int left, int right, int a[]);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int v[maxn], n;
  std::cin >> n;

  for (int i = 0; i < n; ++i) {
    std::cin >> v[i];
  }

  mergeSort(0, n - 1, v);

  for (int i = 0; i < n; ++i) {
    std::cout << v[i] << ' ';
  }

  std::cout << '\n';

  return 0;
}

void mergeSort(int left, int right, int a[]) {
  if (left >= right) return;

  int mid = (left + right) / 2;
  mergeSort(left, mid, a);
  mergeSort(mid + 1, right, a);

  int i = left, j = mid + 1, idx = 0;

  while (i <= mid && j <= right) {
    if (a[i] < a[j]) {
      temp[++idx] = a[i++];
    } else {
      temp[++idx] = a[j++];
    }
  }

  while (i <= mid) {
    temp[++idx] = a[i++];
  }

  while (j <= right) {
    temp[++idx] = a[j++];
  }

  for (int i = left, j = 1; i <= right; ++i, ++j) {
    a[i] = temp[j];
  }
}
