class Solution {
public:
    double myPow(double x, int n) {
      if (n == 0) {
        return 1.00000;
      }

       if (n < 0) {
            x = 1 / x;
            if (n == -(1LL << 31)) { 
               long long absN = n;
                absN = -absN;
                return myPow(x * x, absN / 2) * (absN % 2 == 0 ? 1 : x);
            } else {
                n = -n;
            }
        }

      double res = 1.0;
      while (n > 0) {
        if (n & 1) res *=x;
        x *= x;
        n /= 2;
      }

      return res;
        
    }
};
