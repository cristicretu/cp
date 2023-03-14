#include <fstream>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

ifstream fin("ctc.in");
ofstream fout("ctc.out");

using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;

int n, m;
VVI G, ctc;
VI idx, low;
VB inStack, V;
stack<int> st;
int cnt;

void read();
void tarjan();
void dfs(int node);
void write();

int main() {
  read();
  tarjan();
  write();
  return 0;
}

void write() {
  fout << ctc.size() << '\n';
  for (auto i : ctc) {
    for (auto j : i) {
      fout << j << ' ';
    }
    fout << '\n';
  }
}

void dfs(int node) {
  V[node] = true;
  idx[node] = low[node] = ++cnt;

  st.push(node);
  inStack[node] = true;

  for (const int &y : G[node]) {
    if (!V[y]) {
      // son of node
      dfs(y);
      low[node] = min(low[node], low[y]);
    } else if (inStack[y]) {
      low[node] = min(low[node], idx[y]);
    }
  }

  if (idx[node] == low[node]) { // new CT
    VI c;

    while (!st.empty()) {
      int x = st.top();
      st.pop();
      inStack[x] = false;

      c.emplace_back(x);
      if (x == node) {
        break;
      }
    }

    ctc.push_back(c);
  }
}

void tarjan() {
  for (int x = 1; x <= n; ++x) {
    if (!V[x]) {
      dfs(x);
    }
  }
}

void read() {
  fin >> n >> m;
  G = VVI(n + 1);
  idx = low = VI(n + 1);
  inStack = V = VB(n + 1);

  int x, y;
  while (m--) {
    fin >> x >> y;
    G[x].push_back(y);
  }
}
