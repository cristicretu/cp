#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

ifstream fin("platforma.in");
ofstream fout("platforma.out");

using ll = long long;

static const int N = 15000;

unsigned short opt;
int n;
ll v[N + 1];
ll dp[N];

bool solve1();
void solve2();
void solve3();
void solve4();

int main() {
  fin >> opt;

  if (opt == 1) {
    // cerr << solve1();
    fout << solve1();
  } else if (opt == 2) {
    solve2();
  } else if (opt == 3) {
    solve3();
  } else if (opt == 4) {
    solve4();
  }
}

bool solve1() {
  fin >> n;
  for (int i = 1; i <= n; ++i) {
    fin >> v[i];
  }

  // verificam daca e crescator
  for (int i = 2; i <= n; ++i) {
    if (v[i] < v[i - 1]) {
      return false;
    }
  }

  // verificam intre poz 2 si n / 2 + n % 2
  // treptele au lung. min = 2
  // 						 lung. max = n / 2 + n % 2
  //  n = 5 => min = 2; max = 5 / 2 + 5 % 2 = 2 + 1 = 3
  int i = 2, lim = n / 2 + n % 2;
  while (i <= lim) {
    if (v[i] != v[i + 1]) {
      ++i;
      continue;
    }

    ll val = v[i] - 1;
    ll check = 2 * v[i];
    ++i;
    while (val) {
      if (v[i] != v[i - 1]) {
        return false;
      }
      ++i;
      --val;
    }

    if (v[i] != check) {
      return false;
    }
  }

  return true;
}

void solve2() {
  fin >> n;
  int lim = n / 2 + n % 2;
  ll ans = 1;

  dp[1] = 1;
  for (int i = 2; i < lim; ++i) {
    if (i % 2 == 0) {
      dp[i] = dp[i - 1];
    } else {
      dp[i] = dp[i / 2] + dp[i - 1];
    }
    
    dp[2 * i] += 1;
    ans += dp[i];
  }

  for (int i = 2; i <= lim; ++i) {
    cout << dp[i] << ' ';
  }
  fout << ans + 1;
}

void solve3() {}

void solve4() {}