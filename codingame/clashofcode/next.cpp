#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main() {
  int t;
  cin >> t;
  string ans = "";
  while (t--) {
    int a;
    cin >> a;

    char d = char('z' - a + 'a' - 1);

    ans += (islower(d) ? d : ' ');
  }
  cout << ans;
}