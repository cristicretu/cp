#include <iostream>

using namespace std;
string vocale = "aeiou";
string s;
bool mata;
char sol[15];

bool ok(int k) {
  // for (int i = 0; i < k; ++i) {
  //   if (vocale.find(s[i]) != std::string::npos &&
  //       vocale.find(s[i + 1]) != std::string::npos) {
  //     return false;
  //   } else if (vocale.find(s[i]) == std::string::npos &&
  //              vocale.find(s[i + 1] == std::string::npos)) {
  //     return false;
  //   }
  // }

  return true;
}

void bkt(int k) {
  for (int i = 0, n = s.size(); i < n; ++i) {
    sol[k] = s[i];
    if (ok(k)) {
      if (k == n) {
        for (int j = 0; j < n; ++j) {
          cout << sol[j];
        }
        cout << '\n';
      } else {
        bkt(k + 1);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> s;
  bkt(0);

  return 0;
}
