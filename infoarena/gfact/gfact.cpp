#include <bits/stdc++.h>

typedef long long ll;

std::ifstream fin("gfact.in");
std::ofstream fout("gfact.out");

const int mxn = 45000;

int prime[mxn], nr;

ll ans, b = 1;

std::bitset<mxn> ciur;

inline ll cautare(int d, int e) {
  ll lb = 0, mb, sum, rb = 1LL * d * e;

  while (rb - lb > 1) {
    mb = (lb + rb) >> 1;
    sum = d;
    int temp = 0;

    while (sum <= mb) {
      temp += mb / sum;
      sum *= d;
    }

    if (temp < e) {
      lb = mb;
    } else {
      rb = mb;
    }
  }

  return rb;
}

int main() {
  int p, q, i, j, exp;

  for (i = 2; i <= mxn; i++) {
    if (ciur[i] == 0) {
      prime[nr] = i;
      nr++;
      for (j = i * i; j <= mxn; j += i) ciur[j] = 1;
    }
  }
  ciur[0] = ciur[1] = 1;

  fin >> p >> q;

  i = 0;
  while (prime[i] * prime[i] <= p && p > 1) {
    exp = 0;
    while (p % prime[i] == 0) {
      p /= prime[i];
      exp++;
    }

    exp *= q;
    if (exp > 0) {
      ans = cautare(prime[i], exp);
      b = std::min(ans, b);
    }

    ++i;
  }

  if (p > 1) {
    ans = cautare(p, q);
    b = std::min(b, ans);
  }

  fout << ans;
  return 0;
}
