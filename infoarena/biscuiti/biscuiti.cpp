#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("biscuiti.in");
ofstream fout("biscuiti.out");

static const long long INF = (1LL << 50);
static const int maxN = 100000;

struct tree_node {
  long long minim;
  long long lazy;
  size_t pos;
};

size_t n;
long long initial_sum;
tree_node aib[maxN * 4 + 1];
long long height[maxN + 1];

void update_node(size_t node) {
  aib[node].minim = min(aib[node * 2].minim, aib[node * 2 + 1].minim);

  if (aib[node].minim == aib[node * 2].minim) {
    aib[node].pos = aib[node * 2].pos;
  } else {
    aib[node].pos = aib[node * 2 + 1].pos;
  }

  return;
}

void build(size_t lb, size_t rb, size_t node) {
  if (lb == rb) {
    aib[node].minim = height[lb];
    aib[node].pos = lb;
    return;
  }

  int mb = (lb + rb) / 2;

  build(lb, mb, node * 2);
  build(mb + 1, rb, node * 2 + 1);

  update_node(node);
}

void update_lazy(int node, int lb, int rb) {
  if (aib[node].lazy) {
    aib[node].minim += aib[node].lazy;

    if (lb != rb) {
      aib[node * 2].lazy += aib[node].lazy;
      aib[node * 2 + 1].lazy += aib[node].lazy;
    }

    aib[node].lazy = 0;
  }
}

void update(int node, int lb, int rb, int a, int b, long long val) {
  update_lazy(node, lb, rb);

  if (a <= lb && b >= rb) {
    aib[node].lazy += val;
    update_lazy(node, lb, rb);
  } else {
    int mb = (lb + rb) / 2;

    if (a <= mb) {
      update(node * 2, lb, mb, a, b, val);
    }
    if (b > mb) {
      update(node * 2 + 1, mb + 1, rb, a, b, val);
    }

    update_lazy(node * 2, lb, mb);
    update_lazy(node * 2 + 1, mb + 1, rb);

    update_node(node);
  }
}

int main() {
  fin >> n;
  for (size_t i = 1; i <= n; ++i) {
    fin >> height[i];
    initial_sum += height[i];
  }

  build(1, n, 1);

  long long final_sum = 0;
  for (int i = 0; i < n; ++i) {
    int pos = aib[0].pos;
    final_sum += aib[0].minim;

    update(1, 1, n, pos, pos, INF);

    if (pos != 1) {
      update(1, 1, n, 1, pos - 1, i + 1);
    }
  }

  fout << final_sum - initial_sum << '\n';
  return 0;
}
