class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int profit_with_stock = std::numeric_limits<int>::min();
    int profit_without_stock = 0;

    for (int i = 0; i < prices.size(); i++) {
      profit_with_stock = max(profit_with_stock, profit_without_stock - prices[i]);
      profit_without_stock = max(profit_without_stock, profit_with_stock +  prices[i]);
    }

    return profit_without_stock;
  }
};
