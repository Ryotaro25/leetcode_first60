class Solution {
public:
  int maxProfit(vector<int>& prices) {
    // 後ろから記録する実装
    int max_profit = 0;
    int max_price = prices.back();
    for (int i = prices.size() - 1; i >= 0; i--) {
      max_price = max(prices[i], max_price);
      max_profit = max(max_price - prices[i], max_profit);
    }

    return max_profit;
  }
};
