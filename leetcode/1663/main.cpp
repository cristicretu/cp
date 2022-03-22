class Solution {
public:
    string getSmallestString(int n, int k) {
      // make the smallest possible array at first
      string answer = "";
      for (int i = 0; i < n; ++i) {
        answer += 'a';
      }
      
      // remove 'a'-s "weight" (remove 1)
      k = k - n;
      
      for (int i = n - 1; i >= 0; --i) {
        if (k < 25) {// k is smaller than 'z'
          answer[i] = (char) 'a' + k;
          break;
        } else {
          answer[i] = (char) 'a' + 25;
          k -= 25;
        }
      }
      return answer;
    }
};