#include <fstream>
#include <vector>

using namespace std;

fstream fin("produs_matrice.in", ios::in);
fstream fout("produs_matrice.out", ios::out);

#define ll  long long
#define mat vector<vector<ll> >

mat cn(int n, int m){
    return vector < vector < ll> > (n, vector<ll>(m));
}

mat mult(mat a, mat b) {
  mat c = cn(a.size(), b[0].size());

  for (int i = 0; i < a.size(); ++i) {
    for (int k = 0; k < b.size(); ++k) {
      for (int j = 0; j < b[0].size(); ++j) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  return c;
}

int main() {
  int x, y, z;
  fin >> x >> y;
  mat a = cn(x, y);

  for (int i = 0; i < x; ++i) {
    for (int j = 0; j < y; ++j) {
      fin >> a[i][j];
    }
  }

  fin >> z;
  mat b = cn(y, z);

  for (int i = 0; i < y; ++i) {
    for (int j = 0; j < z; ++j) {
      fin >> b[i][j];
    }
  }

  mat c = mult(a, b);

  for (int i = 0; i < x; ++i, fout << '\n') {
    for (int j = 0; j < z; ++j) {
      fout << c[i][j] << ' ';
    }
  }
  return 0;
}
