class Solution {
public:
    int mySqrt(int x) {
       if (x == 0 || x == 1) {
         return x;
       }
       int lb = 1, rb = x;

       int mb = -1;
       while (lb <= rb) {
         mb = lb + (rb - lb) / 2;
         long long square = static_cast<long long>(mb) * mb;

         if (square > x) {
           rb = mb - 1;
         } else if (square == x) {
           return mb;
         } else {
           lb = mb + 1;
         }
       } 

       return static_cast<int>(std::round(rb));
    }
};
