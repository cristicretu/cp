#include <bits/stdc++.h>

std::ifstream fin("cutie.in");
std::ofstream fout("cutie.out");

int n, m, k;

int main() {
  int t;
  fin >> t;
  while (t--) {
    fin >> n >> k >> m;

    std::set<int> st;
    st.insert(1);
    st.insert(n);

    for (int i = 1; i <= k; ++i) {
      int a;
      fin >> a;
      st.insert(a);
    }

    int count(0), ans(0);
    for (int i = 1; i <= m; ++i) {
      int a;
      fin >> a;

      auto lb = st.lower_bound(a);
      auto rb = lb;
      lb--;

      if ((a - (*lb)) % 2 == ((*rb) - a) % 2)
        ans += (a - (*lb)) % 2;
      else
        count++;
    }
    fout << (count % 2 == 0 && ans % 2 == 0 ? 0 : 1);
  }
  return 0;
}
