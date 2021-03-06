#include <iostream>
#include <fstream>
#include <stack>

std::fstream fin("ascdesc.in", std::ios::in);
std::fstream fout("ascdesc.out", std::ios::out);

const int mxn = 1e5;

int n, v[1 + mxn], st[1 + mxn], dr[1 + mxn], s[1 + mxn];
std::stack<int> stiva;

int main(){
  fin >> n;
  for (int i = 1; i <= n; ++i){
    fin >> v[i];
  }

/*   st[1] = 0; */
/*   for (int i = 2; i <= n; ++i){ */
/*     if (v[i] < v[i - 1]) st[i] = (v[i - 1] - v[i]); */
/*   } */

/*   dr[n] = 0; */
/*   for (int i = n - 1; i >= 1; --i){ */
/*     if (v[i] > v[i - 1]) dr[i] = (v[i] - v[i - 1]); */
/*   } */

  for (int i = 1; i <= n; ++i){
    while (!stiva.empty() && v[i] < v[stiva.top()]){
      stiva.pop();
    }

    if (!stiva.empty()){
      st[i] = stiva.top();
    } else {
      st[i] = 0;
    }
    stiva.push(i);
  }

  for (; !stiva.empty(); stiva.pop());

  for (int i = n; i >= 1; --i){
    while (!stiva.empty() && v[i] > v[stiva.top()]){
      stiva.pop();
    }

    if (!stiva.empty()){
      dr[i] = stiva.top();
    } else {
      dr[i] = n + 1;
    }
    stiva.push(i);
  }

  for (int i = 1; i <= n; ++i){
    s[i] = s[i - 1] + v[i];
  }



  for (int i = 1; i <= n; ++i){
    std::cerr << v[i] << ' ';
  }
  std::cerr << '\n';
  for (int i = 1; i <= n; ++i){
    std::cerr << st[i] << ' ';
  }
  std::cerr << '\n';
  for (int i = 1; i <= n; ++i){
    std::cerr << dr[i] << ' ';
  }
  return 0;
}
