#include <bits/stdc++.h>

std::ifstream fin("parantezare.in");
std::ofstream fout("parantezare.out");

const int mxn = 100000;
int ans[mxn];

int main() {
  std::string s;
  fin >> s;

  std::stack<int> st;
  for (int i = 0u; i < s.size(); i++) {
    if (s[i] == '(') st.push(i);
    if (s[i] == ')') ans[st.top()] = i, st.pop();
  }

  int m;
  fin >> m;
  while (m--) {
    int x;
    fin >> x;
    fout << ans[x] << ' ';
  }
  return 0;
}
