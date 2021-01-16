/**
 *    author: etohirse
 *    created: 16.01.2021 09:34:04
 **/
#include <bits/stdc++.h>

const int mxn = 5e5;
int sum[mxn];

int solve(int n, long long k, int cnt[], int m[]) {
  for (int i = 0; i < n; ++i) {
    for (int j = k - cnt[i]; j >= 0; --j) {
      if (sum[j] != 0 || j == 0)
        sum[j + cnt[i]] = std::max(sum[j + cnt[i]], sum[j] + m[i]);
    }
  }
  return sum[abs(k - n)];
}

// int main() {
//   std::ios_base::sync_with_stdio(false);
//   std::cin.tie(nullptr);

//   int n;
//   long long k;
//   std::cin >> n >> k;
//   int cnt[100], m[100];
//   for (int i = 0; i < n; ++i) std::cin >> cnt[i] >> m[i];
//   std::cout << solve(n, k, cnt, m);
//   return 0;
// }

/*
5 7
3 2
4 3
2 1
2 2
1 1
*/