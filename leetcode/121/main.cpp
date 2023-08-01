class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int maxx = -1, min = prices[0];
        int maxProfit = 0;

        for (int i = 1, size = prices.size(); i < size; ++i) {
          int curr = prices[i];

          if (curr > min && curr > maxx) {
            maxx = curr;
          } else if (curr < min) {
            min = curr;
            maxx = 0;
          }

          // for each pair of min's and max's, we calculate the profit
          profit = maxx - min;
          maxProfit = max(profit, maxProfit);
        }

        return maxProfit;
          }
};
