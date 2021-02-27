#include <iostream>
#include <fstream>
#include <stack>

static const int M = 1e9 + 7, mxn = 1e6;

int n, v[5 + mxn], lb1[5 + mxn], lb2[5 + mxn], rb1[5 + mxn], rb2[5 + mxn];

int mulmod(int a, int b, int c, int d){
  return (1LL * ((1LL * a * b) % M) * ((1LL * c * d) % M)) % M;
}

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> n;
  for (int i = 1; i <= n; ++i){
    std::cin >> v[i];
    lb1[i] = lb2[i] = 0;
    rb1[i] = rb2[i] = n + 1;
  }

  std::stack<int> st1, st2, aux;
  for (int i = 1; i <= n; ++i){
    while (!st2.empty() && v[i] > v[st2.top()]){
      rb2[st2.top()] = i;
      st2.pop();
    }
    while (!st1.empty() && v[i] > v[st1.top()]){
      rb1[st1.top()] = i;
      aux.push(st1.top());
      st1.pop();
    }

    st1.push(i);
    for (; !aux.empty(); aux.pop()){
      st2.push(aux.top());
    }
  }

  for (; !st1.empty(); st1.pop());
  for (; !st2.empty(); st2.pop());

  for (int i = n; i >= 1; --i){
    while (!st2.empty() && v[i] >= v[st2.top()]){
      lb2[st2.top()] = i;
      st2.pop();
    }
    while (!st1.empty() && v[i] >= v[st1.top()]){
      lb1[st1.top()] = i;
      aux.push(st1.top());
      st1.pop();
    }

    st1.push(i);
    for (; !aux.empty(); aux.pop()){
      st2.push(aux.top());
    }
  }

  long long ans(0);
  for (int i = 1; i <= n; ++i){
    if (lb1[i] > 0){
      int a = lb1[i] - lb2[i];
      int b = rb1[i] - i;
      ans = (ans + mulmod(a, b, v[i], v[lb1[i]])) % M;
    }

    if (rb1[i] < n + 1){
      int a = i - lb1[i];
      int b = rb2[i] - rb1[i];
      ans = (ans + mulmod(a, b, v[i], v[rb1[i]])) % M;
    }
  }

  std::cout << ans << '\n';
  return 0;
}
