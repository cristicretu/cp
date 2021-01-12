#include <fstream>
#include <vector>

std::ifstream fin("beaufort.in");
std::ofstream fout("beaufort.out");

void generateString(std::string source, std::string &target) {
  for (int i = 0; i < 25; ++i) target[i] = source[i + 1];
  target[25] = source[0];
}

int main() {
  std::string aux = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", temp;
  std::vector<std::string> mp(26);
  int count = 0;
  temp = aux;
  while (count < 26) {
    mp[count] = temp;
    generateString(aux, temp);
    aux = temp;
    count++;
  }

  for (int i = 0; i < 26; ++i, fout << '\n') fout << mp[i];

  return 0;
}
