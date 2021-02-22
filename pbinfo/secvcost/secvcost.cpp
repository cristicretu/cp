#include <bits/stdc++.h>

typedef long long ll;

std::ifstream fin("secvcost.in");
std::ofstream fout("secvcost.out");

const int mxn = 2e5 + 1;

ll n, m, v[mxn], lb[mxn], rb[mxn], s[mxn];
std::stack<ll> st;

ll Cost(int i) { return (rb[i] - lb[i] + 1) * v[i]; }

int main() {
  fin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    fin >> v[i];

    lb[i] = 1, rb[i] = n;

    while (!st.empty() && v[st.top()] < v[i]) {
      rb[st.top()] = i - 1;
      st.pop();
    }

    if (!st.empty()) lb[i] = st.top() + 1;
    st.push(i);
  }

  for (int i = 1; i <= n; ++i) {
    s[i] = s[i - 1] + Cost(i);
  }

  for (int i = 1; i <= m; ++i) {
    ll a, b;
    fin >> a >> b;
    fout << s[b] - s[a - 1] << '\n';
  }
  return 0;
}
