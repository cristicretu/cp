#include <fstream>
using namespace std;

ifstream fin("aranjamente.in");
ofstream fout("aranjamente.out");

#define cin fin
#define cout fout

int x[10], n, p;

void Afis(int k) {
  for (int j = 1; j <= k; j++) cout << x[j] << " ";
  cout << endl;
}

bool OK(int k) {
  for (int i = 1; i < k; ++i)
    if (x[k] == x[i]) return false;
  return true;
}

bool Solutie(int k) { return k == p; }

void Back(int k) {
  for (int i = 1; i <= n; ++i) {
    x[k] = i;
    if (OK(k))
      if (Solutie(k))
        Afis(k);
      else
        Back(k + 1);
  }
}
int main() {
  cin >> n >> p;
  Back(1);
  return 0;
}