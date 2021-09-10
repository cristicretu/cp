#include <fstream>

using namespace std;

ifstream fin("patrate.in");
ofstream fout("patrate.out");

int a[201][201], n, m;

int main() {
  fin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) fin >> a[i][j];

  int SumaMinima = 0, pi = 0, pj = 0, situatie = 0;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int sumaSus = 0, sumaJos = 0, sumaStanga = 0, sumaDreapta = 0;

      for (int l = 1; l < i; l++) sumaSus = sumaSus + a[l][j];

      for (int l = i + 1; l <= n; l++) sumaJos = sumaJos + a[l][j];

      for (int c = 1; c < j; c++) sumaStanga = sumaStanga + a[i][c];

      for (int c = j + 1; c <= m; c++) sumaDreapta = sumaDreapta + a[i][c];

      if (sumaJos + sumaStanga + a[i][j] > SumaMinima) {
        SumaMinima = sumaJos + sumaStanga + a[i][j];
        pi = i;
        pj = j;
        situatie = 1;
      }

      if (sumaSus + sumaStanga + a[i][j] > SumaMinima) {
        SumaMinima = sumaSus + sumaStanga + a[i][j];
        pi = i;
        pj = j;
        situatie = 2;
      }

      if (sumaJos + sumaDreapta + a[i][j] > SumaMinima) {
        SumaMinima = sumaJos + sumaDreapta + a[i][j];
        pi = i;
        pj = j;
        situatie = 3;
      }

      if (sumaSus + sumaDreapta + a[i][j] > SumaMinima) {
        SumaMinima = sumaSus + sumaDreapta + a[i][j];
        pi = i;
        pj = j;
        situatie = 4;
      }
    }

  fout << SumaMinima << '\n' << pi << " " << pj << " ";

  if (situatie == 1)  // L-ul e orientat in stanga si in jos
    fout << -pj << " " << -(n - pi + 1) << '\n';

  else if (situatie == 2)  // L-ul e orientat in stanga si in sus
    fout << -pj << " " << pi << "\n";

  else if (situatie == 3)  // L-ul e orientat in dreapta si in jos
    fout << (m - pj + 1) << " " << -(n - pi + 1) << "\n";

  else  // L-ul e orientat in dreapta si in sus
    fout << (m - pj + 1) << " " << pi << "\n";
  return 0;
}