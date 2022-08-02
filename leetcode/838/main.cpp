#include <vector>

class Solution {
public:
    string pushDominoes(string dominoes) {
        unsigned n = dominoes.size();
        int score[n];
      
        for (unsigned i = 0; i < n; ++i) {
          score[i] = 0;
        }
      
        int power = 0;
        for (unsigned i = 0; i < n; ++i) {
            if (dominoes[i] == 'R') power = n;
            else if (dominoes[i] == 'L') power = 0;
            else power = max(power - 1, 0);
            score[i] += power;
        }
      
        power = 0;
        for (unsigned i = n - 1; i >= 0; --i) {
            if (dominoes[i] == 'L') power = n;
            else if (dominoes[i] == 'R') power = 0;
            else power = max(power - 1, 0);
            score[i] -= power;
        }
        
        string ans = "";
        
        for (unsigned i = 0; i < n; ++i) {
            ans += score[i] > 0 ? 'R' : score[i] < 0 ? 'L' : '.';
        }
        
        return ans;
    }
};
