#include <iostream>
#include <fstream>
#include <stack>
#include <vector>

std::fstream fin("strabunica.in", std::ios::in);
std::fstream fout("strabunica.out", std::ios::out);

const int mxn = 200005;

int n, v[mxn], lb[mxn], rb[mxn];
std::stack<int> st;

int main(){
	fin >> n;
  for (int i = 1; i <= n; ++i){
    fin >> v[i];
  }

  for (int i = 1; i <= n; ++i){
    while (!st.empty() && v[i] <= v[st.top()]){
      st.pop();
    }
    if (st.empty()){
      rb[i] = i - 1;
    } else {
      rb[i] = i - st.top() - 1;
    }
    st.push(i);
  }

  while (!st.empty()){
    st.pop();
  }

  for (int i = n; i >= 0; --i){
    while (!st.empty() && v[i] <= v[st.top()]){
      st.pop();
    }

    if (st.empty()){
      lb[i] = n - i;
    } else {
      lb[i] = st.top() - i - 1;
    }
    st.push(i);
  }

  long long ans = 0;
  for (int i = 1; i <= n; ++i){
    ans = std::max(ans, 1LL * v[i] * (rb[i] + lb[i] + 1));
  }
  /* std::cerr << ans; */
  fout << ans;
  return 0;
}
