#include <iostream>
#include <stack>
#include <fstream>

std::fstream fin("nrsubsecv.in", std::ios::in);
std::fstream fout("nrsubsecv.out", std::ios::out);

static const int mxn = 1e6;

int64_t n, m, v[1 + mxn], st[1 + mxn], dr[1 + mxn], s[1 + mxn];

int main(){
  fin >> n >> m;
  for (int64_t i = 1; i <= n; ++i){
    fin >> v[i];
  }

  std::stack<int64_t> stiva;

  for (int64_t i = 1; i <= n; ++i){
    while (!stiva.empty() && v[i] < v[stiva.top()]){
      stiva.pop();
    }
    st[i] = ((!stiva.empty()) ? stiva.top() + 1 : 1);
    stiva.push(i);
  }
  for (; !stiva.empty(); stiva.pop());
  for (int64_t i = n; i; --i){
    while (!stiva.empty() && v[i] <= v[stiva.top()]){
      stiva.pop();
    }
    dr[i] = ((!stiva.empty()) ? stiva.top() - 1 : n);
    stiva.push(i);
  }
  for (int64_t i = 1; i <= n; ++i){
    s[v[i]] += (i + 1 - st[i]) * (dr[i] + 1 - i);
  }
  for (int64_t i = 0; i <= mxn; ++i){
    s[i] += s[i - 1];
  }

  while(m--){
    int64_t a, b;
    fin >> a >> b;
    fout << s[b] - s[a - 1] << '\n';
  }

  return 0;
}
