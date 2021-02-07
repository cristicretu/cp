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
  int v[25] = {0};
  int n;
  cin >> n;
  int s = 0;
  while (n--) {
    int a, b;
    cin >> a >> b;
    for (int i = a; i < b; ++i) v[i] = 1;
  }
  for (int i = 0; i <= 24; ++i) s += v[i];
  cout << s;
}