/**
 *    author: etohirse
 *    created: 24.12.2020 17:55:15
 **/
#include <fstream>
#include <stack>

std::ifstream fin("cntsubsirmax.in");
std::ofstream fout("cntsubsirmax.out");

std::stack<int> st;
const int M = 1e9 + 7;

int main() {
  std::string s;
  fin >> s;
  s = ' ' + s;
  int cnti(0), ans(0);
  for (int i = 0u; i < s.size(); ++i) {
    while (!st.empty() and s[i] > s[st.top()]) cnti -= st.top(), st.pop();
    st.push(i);
    cnti = (cnti + i) % M;
    ans = (ans + cnti) % M;
  }
  fout << ans;
  return 0;
}
