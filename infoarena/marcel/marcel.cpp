#include <bits/stdc++.h>

class InputReader {
 public:
  InputReader() {}

  InputReader(const char* file_name) {
    input_file = fopen(file_name, "r");

    cursor = 0;

    fread(buffer, SIZE, 1, input_file);
  }

  inline InputReader& operator>>(int& n) {
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

  inline InputReader& operator>>(long long& n) {
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
  FILE* input_file;

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

InputReader fin("marcel.in");
class OutParser {
#pragma warning(disable : 4996)

 private:
  FILE* fout;

  char* buff;

  int sp;

  void write_ch(char ch) {
    if (sp == 50000) {
      fwrite(buff, 1, 50000, fout);

      sp = 0;

      buff[sp++] = ch;

    } else

      buff[sp++] = ch;
  }

 public:
  OutParser(const char* name) {
    fout = fopen(name, "w");

    buff = new char[50000]();

    sp = 0;
  }

  ~OutParser() {
    fwrite(buff, 1, sp, fout);

    fclose(fout);
  }

  OutParser& operator<<(int vu32) {
    if (vu32 <= 9)

      write_ch(vu32 + '0');

    else {
      (*this) << (vu32 / 10);

      write_ch(vu32 % 10 + '0');
    }

    return *this;
  }

  OutParser& operator<<(char ch) {
    write_ch(ch);

    return *this;
  }

  OutParser& operator<<(const char* ch) {
    while (*ch) {
      write_ch(*ch);

      ++ch;
    }

    return *this;
  }
};

OutParser fout("marcel.out");

const int mxn = 140, M = 1000000007;
int n, x, ans, a[mxn][mxn], sl[mxn][mxn], sc[mxn][mxn], dp[mxn][mxn][mxn][mxn];

int main() {
  std::ios_base::sync_with_stdio(NULL);
  fin >> n >> x;

  int i, j, l, k, l1, l2, c1, c2;

  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j) {
      fin >> a[i][j];
      sl[i][j] = a[i][j] + sl[i][j - 1];
      sc[j][i] = a[i][j] + sc[j][i - 1];
    }

  dp[0][0][0][0] = 1;

  for (i = 0; i <= n; ++i)
    for (j = 0; i + j <= n; ++j)
      for (k = 0; k <= n; ++k)
        for (l = 0; k + l <= n; ++l) {
          ans = (ans + dp[i][j][k][l]) % M;
          l1 = i + 1, l2 = n - j, c1 = k + 1, c2 = n - l;
          if (sl[l1][c2] - sl[l1][c1 - 1] >= x)
            dp[i + 1][j][k][l] = (dp[i + 1][j][k][l] + dp[i][j][k][l]) % M;
          if (sl[l2][c2] - sl[l2][c1 - 1] >= x)
            dp[i][j + 1][k][l] = (dp[i][j + 1][k][l] + dp[i][j][k][l]) % M;
          if (sc[c1][l2] - sc[c1][l1 - 1] >= x)
            dp[i][j][k + 1][l] = (dp[i][j][k + 1][l] + dp[i][j][k][l]) % M;
          if (sc[c2][l2] - sc[c2][l1 - 1] >= x)
            dp[i][j][k][l + 1] = (dp[i][j][k][l + 1] + dp[i][j][k][l]) % M;
        }
  fout << ans << '\n';
  return 0;
}
