#include <iostream>

int n, sol[11], fv[5];

inline void afis() {
  for (int i = 1; i <= n * (n + 1) / 2; ++i) {
    printf("%d", sol[i]);
  }
  printf("\n");
}

inline void bkt(int k) {
  for (int i = 1; i <= n; ++i) {
    if (fv[i]) {
      sol[k] = i;
      fv[i] -= 1;
      if (k == n * (n + 1) / 2)
        afis();
      else
        bkt(k + 1);
      fv[i] += 1;
    }
  }
}

int main(void) {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    fv[i] = i;
  }

  bkt(1);
}

// #include <algorithm>
// #include <iostream>
// #include <vector>

// int main() {
//   int n;
//   std::cin >> n;

//   std::vector<int> v;
//   if (n >= 1) v.push_back(1);
//   if (n >= 2) {
//     v.push_back(2);
//     v.push_back(2);
//   }
//   if (n >= 3) {
//     v.push_back(3);
//     v.push_back(3);
//     v.push_back(3);
//   }
//   if (n >= 4) {
//     v.push_back(4);
//     v.push_back(4);
//     v.push_back(4);
//     v.push_back(4);
//   }

//   do {
//     for (int i = 0; i < n * (n + 1) / 2; ++i) {
//       std::cout << v[i];
//     }
//     std::cout << '\n';
//   } while (std::next_permutation(v.begin(), v.end()));
// }