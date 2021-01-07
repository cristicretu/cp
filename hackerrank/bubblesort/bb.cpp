#include <bits/stdc++.h>

class Read {
 public:
  template <class T>
  Read& operator>>(T& number) {
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if (c == '-') {
      negative = true;
      c = getchar();
    }
    for (; (c > 47 && c < 58); c = getchar()) number = number * 10 + c - 48;
    if (negative) number *= -1;
    return *this;
  }
};
Read cin;
int main() {
  std::ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  std::vector<int> v(n);
  for (auto& i : v) cin >> i;

  bool sortat;
  int ans = 0;
  do {
    sortat = true;
    for (int i = 0; i < n - 1; i++)
      if (v[i] > v[i + 1]) {
        std::swap(v[i], v[i + 1]);
        ans++;
        sortat = false;
      }
  } while (!sortat);
  std::cout << "Array is sorted in " << ans << " swaps.\n";
  std::cout << "First element: " << v[0] << '\n';
  std::cout << "Last element: " << v[n - 1] << '\n';
  std::cout << ans;
  return 0;
}
