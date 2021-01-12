#include <bits/stdc++.h>

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

  std::string key, msg;
  fin >> key >> msg;

  int n = key.size();
  for (unsigned i = 0; i < msg.size(); ++i) {
    char c = key[i % n];
    for (int j = 0; j < 26; ++j) {
      if (mp[j][int(msg[i]) % 65] == c) fout << char(j + 65);
    }
  }

  return 0;
}
