#include <iostream>
#include <algorithm>
#include <fstream>

typedef long long ll;

std::fstream fin("distincte.in", std::ios::in);
std::fstream fout("distincte.out", std::ios::out);

static const int mxn = 1e5, M = 666013;

ll n, m, k, upd[1 + mxn];

struct Query{
  ll l, r, orig;

  bool operator < (const Query &other) const{
    if (r == other.r) return l < other.l;
    return r < other.r;
  }
}queries[1 + mxn];

struct Aib{
  ll v[1 + mxn];
  
  void update(ll poz, ll val){
    for (ll i = poz; i <= n; i += i & (-i))
        v[i] += val;
  }

  ll query(ll poz){
    ll s = 0;
    for (ll i = poz; i >= 1; i -= i & (-i))
        s += v[i];
    return s;
  }
}aib;

ll v[1 + mxn], ans[1 + mxn];

int main() {
  fin >> n >> k >> m;

  for (ll i = 1; i <= n; ++i){
    fin >> v[i];
    aib.update(i, v[i]);
  }

  for (ll i = 1; i <= m; ++i){
    fin >> queries[i].l >> queries[i].r;
    queries[i].orig = i;
  }
  
  std::sort(queries + 1, queries + m + 1);
  ll poz = 1;
  for (ll i = 1; i <= m; ++i){
    while (poz <= queries[i].r){
      if (upd[v[poz]]){
        aib.update(upd[v[poz]], -v[poz]);
      }
      upd[v[poz]] = poz;
      poz++;
    }

    ans[queries[i].orig] = aib.query(queries[i].r) -
                           aib.query(queries[i].l - 1);
  }

  for (ll i = 1; i <= m; ++i){
    std::cerr << m << ' ';
    std::cerr << ans[i] % M << ' ';
    fout << ans[i] % M << '\n';
  }
  
  return 0;
}
