class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int maximum_profit = 0;
    int minimum_price = std::numeric_limits<int>::max();
    for (int i = 0; i < prices.size(); i++) {
      minimum_price = min(prices[i], minimum_price);
      maximum_profit = max(prices[i] - minimum_price, maximum_profit);
    }

    return maximum_profit;
  }
};
