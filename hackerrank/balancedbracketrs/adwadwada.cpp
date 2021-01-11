#include <bits/stdc++.h>

bool solve(std::string s) {
  std::stack<char> st;
  for (char d : s) {
    if (d == '(')
      st.push(')');
    else if (d == '[')
      st.push(']');
    else if (d == '{')
      st.push('}');
    else if (st.empty() || st.top() != d)
      return false;
    else
      st.pop();
  }
  return st.empty();
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int T;
  std::cin >> T;
  while (T--) {
    std::string s;
    std::cin >> s;
    std::cout << (solve(s) ? "YES\n" : "NO\n");
  }
  return 0;
}
