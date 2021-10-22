#include <bits/stdc++.h>

typedef long long ll;
int n;
ll d;
ll v[1001];

inline bool ok(ll mb) {
  for (int i = 0; i < n; ++i) {
    if (mb % v[i]) {
      mb += (v[i] - mb % v[i]);
    }
  }

  return mb <= d;
}

void solve() {
  std::cin >> n >> d;

  for (int i = 0; i < n; ++i) {
    std::cin >> v[i];
  }

  ll lb = 0, rb = d;
  while (lb < rb) {
    ll mb = (lb + rb + 1) / 2;

    if (ok(mb)) {
      lb = mb;
    } else {
      rb = mb - 1;
    }
  }

  std::cout << lb;
}

int main() {
  using namespace std;

  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    solve();
    cout << '\n';
  }

  return 0;
}