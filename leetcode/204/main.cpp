class Solution {
public:
    int countPrimes(int n) {
       vector<int> ciur(n + 1, 1);

       for (int i = 4; i <= n; i +=2) {
         ciur[i] = 0;
       } 

       for (int i = 3; i * i <= n; i +=2) {
         if (ciur[i] == 1) {
           for (int j = i * i; j <= n; j += i) {
             ciur[j] = 0;
           }
         }
       }

       int ans = 0;
       for (int i = 2; i < n; ++i) {
         ans += ciur[i];
       }

       return ans;
    }
};
