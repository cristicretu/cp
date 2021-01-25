#include <bits/stdc++.h>

std::ifstream fin("random.in");
std::ofstream fout("random.out");

int main() {
  int n;
  fin >> n;
  if (n == 1982) fout << "Robert Tarjan";
  if (n == 1986) fout << "Leslie Valiant";
  if (n == 1990) fout << "Alexander Razborov";
  if (n == 1994) fout << "Avi Wigderson";
  if (n == 1998) fout << "Peter Shor";
  if (n == 2002) fout << "Madhu Sudan";
  if (n == 2006) fout << "Jon Kleinberg";
  if (n == 2010) fout << "Daniel Spielman";
  if (n == 2014) fout << "Subhash Khot";
  return 0;
}
