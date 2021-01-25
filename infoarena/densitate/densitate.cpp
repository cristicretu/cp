#include <bits/stdc++.h>

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

InputReader fin("densitate.in");

ofbuffer fout("densitate.out");

std::bitset<500005> ciur;

int n, q, s[500005];

int main() {
  fin >> n >> q;

  ciur[1] = ciur[0] = 1;
  for (int i = 4; i <= n; i += 2) ciur[i] = 1;
  for (int i = 3; i * i <= n; i += 2)
    if (!ciur[i])
      for (int j = i * i; j <= n; j += i) ciur[j] = 1;

  for (int i = 1; i <= n; ++i)
    if (!ciur[i])
      s[i] = 1 + s[i - 1];
    else
      s[i] = s[i - 1];

  while (q--) {
    int a, b;
    fin >> a >> b;
    fout << s[b] - s[a - 1] << '\n';
  }
  return 0;
}
