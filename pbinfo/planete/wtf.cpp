#include <iostream>
#include <stack>

const int mxn = 200000;

int n;
int mat[1 + mxn];
bool viz[1 + mxn];
bool recStack[1 + mxn];

void dfs(int node) {
  viz[node] = true;

  int vecin = mat[node];
  if (!viz[vecin]) {
    std::stack<int> st;
    st.push(vecin);
    viz[vecin] = true;
    process(vecin, st);
  }
}

void dfs(int node) {
  if (viz[node]) {
    if (node == start) printf("we gottem");
    return;
  }
  viz[node] = true;
}

int main(void) {
  int i;
  scanf("%d", &n);

  for (i = 1; i <= n; ++i) {
    scanf("%d", &mat[i]);
  }

  for (i = 1; i <= n; ++i) {
    viz[i] = false;
    recStack[i] = false;
  }

  for (i = 1; i <= n; ++i) return 0;
}