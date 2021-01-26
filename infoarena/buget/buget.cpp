#include <bits/stdc++.h>

typedef unsigned long long ll;

class InputReader

{
 public:
  static const int BUFF_SIZE = 1 << 17;

  FILE* fin;

  int bp;

  char buff[BUFF_SIZE];

  InputReader(const char* file_name)

  {
    fin = fopen(file_name, "r");

    bp = BUFF_SIZE - 1;
  }

  void close()

  {
    fclose(fin);
  }

  void adv()

  {
    if (++bp == BUFF_SIZE)

    {
      fread(buff, sizeof(char), BUFF_SIZE, fin);

      bp = 0;
    }
  }

  InputReader& operator>>(int& num)

  {
    num = 0;

    while (isdigit(buff[bp]) == false) adv();

    while (isdigit(buff[bp]))

    {
      num = num * 10 + buff[bp] - '0';

      adv();
    }

    return *this;
  }
};

class ofbuffer

{
 private:
  char* b_text;

  int b_capacity, b_size;

  FILE* file;

  inline void b_put_ch(char ch)

  {
    b_text[b_size++] = ch;

    if (b_size == b_capacity) b_flush();
  }

  void b_put_nr(int x)

  {
    if (x > 0)

    {
      b_put_nr(x / 10);

      b_put_ch('0' + x % 10);
    }
  }

 public:
  inline ofbuffer(char* path, int capacity = 16000)

  {
    file = fopen(path, "w");

    b_text = new char[capacity];

    b_capacity = capacity;

    b_size = 0;
  }

  inline ~ofbuffer()

  {
    if (b_size != 0) b_flush();
  }

  inline void b_flush(void)

  {
    fwrite(b_text, 1, b_size, file);

    b_size = 0;
  }

  inline ofbuffer& operator<<(int v)

  {
    if (v == 0)

      b_put_ch('0');

    else

      b_put_nr(v);

    return *this;
  }

  inline ofbuffer& operator<<(char v)

  {
    b_put_ch(v);

    return *this;
  }

  inline void close()

  {
    b_flush();

    fclose(file);
  }
};

InputReader fin("buget.in");

ofbuffer fout("buget.out");

const int mxn = 1e5 + 2;

int n;
ll b, p[mxn];

bool ok(ll mb) {
  ll sum = 0;
  for (int i = 1; i <= n; ++i)
    if (p[i] > mb)
      sum += mb;
    else
      sum += p[i];

  return sum <= b;
}

int main() {
  fin >> n >> b;

  for (int i = 1; i <= n; ++i) fin >> p[i];

  ll lb = 0, rb = b, ans = 0;
  while (rb - lb > 1) {
    ll mb = lb + (rb - lb) / 2;

    if (ok(mb))
      lb = mb, ans = std::max(ans, lb);
    else
      rb = mb;
  }

  fout << ans;

  return 0;
}
