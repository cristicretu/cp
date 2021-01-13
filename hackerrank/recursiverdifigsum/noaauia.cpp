#include <bits/stdc++.h>

int digit(std::string s) {
  int sum = 0;
  for (char d : s) sum += int(d - '0');
  if (sum < 9)
    return sum;
  else {
    std::string newS = std::to_string(sum);
    return digit(newS);
  }
}

int num1(long long n) {
  if (n <= 9) return n;
  long long sum = 0;
  while (n) {
    sum += n % 10;
    n /= 10;
  }
  return num1(sum);
}

int main() {
  std::ios_base::sync_with_stdio(false);

  std::string s;
  int k;
  std::cin >> s >> k;

  long long sum = 0;
  for (int i = 0; i < s.size(); ++i) {
    sum += s[i] - '0';
  }
  std::cout << num1(sum * k);

  return 0;
}
