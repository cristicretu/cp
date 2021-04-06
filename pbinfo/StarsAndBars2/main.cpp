#include <iostream>

int v[1001];

void comb(int n, int k){
  for (int i = 1; i <= k; ++i){
    v[i] = n - i + 1;
  }
  for(int i = 1 ; i <= k ; i++)
    {
        int x = i , d = 2;
        while(x > 1)
        {
            if(x % d == 0)
            {
                int p = 0;
                for(int j = 1 ; j <= k ; j++)
                    if(v[j] % d == 0) p = j;
                v[p] /= d;
                x /= d;
            }
            else d++;
            if(d * d > x) d = x;
        }
    }
    int r[1001];
    r[0] = 1 , r[1] = 1;
    for(int i = 1 ; i <= k ; i++)
    {
        int t = 0;
        for(int j = 1 ; j <= r[0] ; j++)
        {
            int x = t + r[j] * v[i];
            r[j] = x % 10;
            t = x / 10;
        }
        while(t) r[++r[0]] = t % 10 , t /=10;
    }
    for(int i = r[0] ; i > 0 ; i--)
       std::cout << r[i];
}

int main(){
  int n, k;
  std::cin >> n >> k;
  comb(n - 1, k - 1);
  return 0;
}
