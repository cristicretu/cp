/**
 *    author: etohirse
 *    created: 26.12.2020 15:54:25
 **/
#include <bits/stdc++.h>
using namespace std;
class InputReader {
 public:
  InputReader() {}
  InputReader(const char *file_name) {
    input_file = fopen(file_name, "r");
    cursor = 0;
    fread(buffer, SIZE, 1, input_file);
  }
  inline InputReader &operator>>(int &n) {
    while ((buffer[cursor] < '0' || buffer[cursor] > '9') &&
           buffer[cursor] != '-') {
      advance();
    }
    int sign = 1;
    if (buffer[cursor] == '-') {
      sign = -1;
      advance();
    }
    n = 0;
    while ('0' <= buffer[cursor] && buffer[cursor] <= '9') {
      n = n * 10 + buffer[cursor] - '0';
      advance();
    }
    n *= sign;
    return *this;
  }
  inline InputReader &operator>>(long long &n) {
    while ((buffer[cursor] < '0' || buffer[cursor] > '9') &&
           buffer[cursor] != '-') {
      advance();
    }
    int sign = 1;
    if (buffer[cursor] == '-') {
      sign = -1;
      advance();
    }
    n = 0;
    while ('0' <= buffer[cursor] && buffer[cursor] <= '9') {
      n = n * 10 + buffer[cursor] - '0';
      advance();
    }
    n *= sign;
    return *this;
  }

 private:
  FILE *input_file;
  static const int SIZE = 1 << 17;
  int cursor;
  char buffer[SIZE];
  inline void advance() {
    ++cursor;
    if (cursor == SIZE) {
      cursor = 0;
      fread(buffer, SIZE, 1, input_file);
    }
  }
};

InputReader fin("beyond_the_wall.in");
ofstream fout("beyond_the_wall.out");

const int mxn = 4e4 + 2;
pair<int, int> av[mxn];

int main() {
  int n, q;
  fin >> n >> q;
  for (int i = 0; i < n; ++i) {
    fin >> av[i].first >> av[i].second;
  }

  while (q--) {
    int a, b;
    long long ans(0);
    fin >> a >> b;

    for (int i = 0; i < n; ++i)
      ans += (av[i].second < a * av[i].first + b) ? 1 : 0;

    fout << ans << '\n';
  }
  return 0;
}
