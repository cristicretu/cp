#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<int> height(n);

  for (auto &i : height)
  {
    cin >> i;
  }
}