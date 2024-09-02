struct Solution;

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut profit = 0;
        let mut min = prices[0];
        let mut max = prices[0];

        for i in 1..prices.len() {
            if prices[i] < min {
                min = prices[i];
                max = prices[i];
            } else if prices[i] > max {
                max = prices[i];
                profit = profit.max(max - min);
            }
        }

        profit
    }
}

fn main() {
    let mut prices = vec![7, 1, 5, 3, 6, 4];
    assert_eq!(Solution::max_profit(prices), 5);

    prices = vec![7, 6, 4, 3, 1];
    assert_eq!(Solution::max_profit(prices), 0);
}
