#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

std::ifstream fin("aria.in");
std::ofstream fout("aria.out");

using VD = vector<pair<double, double>>;

unsigned long n;
VD arie;

void read();
void solve();

int main() {
  read();
  solve();
  return 0;
}

void solve() {
  double ans = 0;

  for (unsigned long i = 0; i < n; ++i) {
    ans +=
        arie[i].first * arie[i + 1].second - arie[i + 1].first * arie[i].second;
  }

  ans /= 2.0;
  if (ans == (int)ans) {
    fout << ans << '\n';
  } else {
    fout << std::fixed << std::setprecision(5) << ans << '\n';
  }
}

void read() {
  fin >> n;
  arie = VD(n);

  for (auto &i : arie) {
    fin >> i.first >> i.second;
  }
  arie.emplace_back(arie[0]);
}
