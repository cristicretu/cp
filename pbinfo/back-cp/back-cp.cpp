#include <algorithm>
#include <iostream>

class Read {
 public:
  template <class T>
  Read& operator>>(T& number) {
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if (c == '-') {
      negative = true;
      c = getchar();
    }
    for (; (c > 47 && c < 58); c = getchar()) number = number * 10 + c - 48;
    if (negative) number *= -1;
    return *this;
  }
};
Read cin;

int st[30];
int n, m;

bool ok(std::string a) {
  int i = 0;
  while (a[i] != NULL) {
    if (a[i] == 'C') {
      i++;
      // we are on the hunt for another C
      int j = i;
      while (a[j] != 'C' && a[j] != NULL) {
        j++;
      }

      if (a[j] == 'C') {
        // we found a C
        while (a[i] != 'C') {
          if (a[i] == 'P') {
            return false;
          }
          i++;
        }
      }
    } else {
      i++;
    }
  }

  // std::cout << a << '\n';
  return true;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  cin >> n >> m;
  std::string s = "";

  for (int i = 0; i < n; ++i) {
    s += 'C';
  }

  for (int i = 0; i < m; ++i) {
    s += 'P';
  }

  do {
    bool ok = true;

    int i = 0;
    while (s[i] != NULL) {
      if (s[i] == 'C' && s[i + 1] == 'P' && s[i + 2] == 'C') {
        ok = false;
      }
      i++;
    }

    if (ok == true) std::cout << s << '\n';
  } while (std::next_permutation(s.begin(), s.end()));
  return 0;
}
