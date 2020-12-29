/**
 *    author: etohirse
 *    created: 29.12.2020 09:12:03
 **/
#include <bits/stdc++.h>

bool solve(std::string s) {
  if (s[0] == ')' or s[s.size() - 1] == '(' or s.size() % 2) return false;
  return true;
}

int main() {
  using namespace std;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cout << ((solve(s)) ? "YES\n" : "NO\n");
  }
  return 0;
}