#include <iostream>
#include <fstream>
#include <stack>

#define int long long

std::ifstream fin("secvcost.in");
std::ofstream fout("secvcost.out");

static const int mxn = 2e5;

int n, m, st[1 + mxn], dr[1 + mxn], v[1 + mxn], s[1 + mxn];
std::stack<int>stiva;

int32_t main() {
  fin >> n >> m;
  for (int i = 1; i <= n; ++i){
    fin >> v[i];
    st[i] = 1, dr[i] = n;
    while (!stiva.empty() && v[i] > v[stiva.top()]){
      dr[stiva.top()] = i - 1;
      stiva.pop();
    }
    if (!stiva.empty()) st[i] = stiva.top() + 1;
    stiva.push(i);
  }

  for (int i = 1; i <= n; ++i){
    s[i] = s[i - 1] + (dr[i] - st[i] + 1) * v[i];
  }

  for (int i = 1; i <= m; ++i){
    int a, b;
    fin >> a >> b;
    fout << s[b] - s[a - 1] << '\n';
  }
  return 0;
}
