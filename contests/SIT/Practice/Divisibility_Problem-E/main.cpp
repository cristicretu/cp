#include <iostream>

int n;

unsigned long long sol, diviz;

void solution(unsigned long long number, int digitCount) {
  if (digitCount == n - 1) {
    if ((number * 10 + 2) % diviz == 0) {
      sol = number * 10 + 2;
      return;
    }
  } else if (digitCount < n - 1) {
    solution(number * 10 + 1, digitCount + 1);
    solution(number * 10 + 2, digitCount + 1);
  }
}

int main() {
  std::cin >> n;
  diviz = 1LL << n;
  solution(0, 0);
  if (sol)
    std::cout << sol << '\n';
  else
    std::cout << '-1\n';
}