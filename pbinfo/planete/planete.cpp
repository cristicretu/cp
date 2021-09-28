#include <iostream>
#include <unordered_set>
#include <vector>

const unsigned mxn = 200000;

int n;
std::unordered_set<int> s;
std::vector<int> mat[mxn];
// mat[i] = urm. nod al nodului i

// std::vector<std::pair<int, int> > mat[mxn];
// mat.first = nod curent

void dfs(int node) {
  int vecin = mat[node];
  for (int i = 1; i <= node; ++i) {
    std::cout << "okm";
  }
  if (s.find(vecin) != s.end()) {
    return;
  }

  s.insert(vecin);
  dfs(vecin);
}

int main() {
  int i;
  scanf("%d", &n);

  for (i = 1; i <= n; ++i) {
    std::cin >> mat[i];
  }

  // pt. fiecare nod
  // curatam setul si parcurgem vecinii pana cand ajungem
  // la un node deja introdus in set

  // atentie la cicluri!

  for (i = 1; i <= n; ++i) {
    s.clear();
    s.insert(i);
    // dfs(i);
    printf("%d ", s.size());
  }

  printf("\n");

  return 0;
}
