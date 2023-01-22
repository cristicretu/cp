#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream fin("inv.in");
ofstream fout("inv.out");

const int MAX_N = 1e5, MOD = 9917;

int n;
int aib[MAX_N + 1];
long long ans;
vector<pair<int,int> > v;

void update(int x, int val);
int query(int x);

int main() {
  fin >> n;
  int x;
  for (int i = 0; i < n; ++i) {
    fin >> x;
    v.emplace_back(x, i + 1);
  }

  sort(v.begin(), v.end(), greater<pair<int,int>>());

  for (int i = 0; i < n; ++i) {
    x = v[i].second; // real pos
    ans += 1LL * query(x);
    update(x, 1);
  }
  
  fout << ans % MOD << '\n';
  return 0;
}

int query(int x) {
  int sum = 0;
  for (int i = x; i; i -= i & (-i)) {
    sum += aib[i];
  }
  return sum;
}

void update(int x, int val) {
  for (int i = x; i <= n; i += i & (-i)) {
    aib[i] += val;
  }
}
