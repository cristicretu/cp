#include <iostream>
#include <algorithm>

using namespace std;

long long n, v[100005];

int main() {
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
  }

  sort(v + 1, v + n + 1);

  if (v[1] * v[2] > v[n] * v[n - 1]) cout << v[1] * v[2] << '\n';
  else cout << v[n] * v[n - 1] << '\n';
}
