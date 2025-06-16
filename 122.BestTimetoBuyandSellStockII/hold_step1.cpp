class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty()) {
      return 0;
    }
    int max_profit = 0;
    int hold_stock = NOTHOLD;
    for (int price : prices) {
      if (hold_stock == NOTHOLD) {
        hold_stock = price;
        continue;
      }

      if (price > hold_stock) {
        max_profit += price - hold_stock;
        hold_stock = price;
        continue;
      }
 
      hold_stock = price;
    }
    return max_profit;
  }

private:
  static constexpr int NOTHOLD = -1;
};