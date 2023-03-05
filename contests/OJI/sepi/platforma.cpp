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
int dp[N];

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
  /*
  ideea e ca tu la fiecare pas, daca iti este par, nu ai cum sa generezei un sir
  nou asadar, numarul tau de variante e la fel ca si la i-1 daca pasul iti este
  impar, atunci tu mai ai o secventa noua, in care fie ii lasi numarul lui la
  final, fie face parte dintr-o treapta care incepe la i si se termina la 2*i-1
  */

  dp[2] = 1;
  for (int i = 3; i <= n; ++i) {
    if (i % 2) {
      dp[i] = 1;
      dp[2 * i] += 1 + dp[i];
    } else {
      dp[i] += dp[i - 1];
    }
  }

  cout << dp[n];
  for (int i = 1; i <= n; ++i) {
    cout << dp[i] << ' ';
  }

  // for (int j = 1; j <= n; j++) {
  // 		ans += dp[n][j]; // suma tuturor numarului de variante la ultimul
  // pas impar
  // }

  // for (int i = 2; i <= lim; ++i) {
  // 		dp[i] = 1;
  // 		for (int j = 2; j <= i / 2 + i % 2; ++j) {
  // 				dp[i] += dp[i * j];
  // 		}
  // }
  //
  // ll ans = 0;
  // for (int i = 2; i <= lim; ++i) {
  // 		ans += dp[i];
  // }
  //
  // fout << ans;
}

void solve3() {}

void solve4() {}