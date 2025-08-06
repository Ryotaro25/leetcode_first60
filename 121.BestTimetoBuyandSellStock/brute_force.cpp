// LTEとなる
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int maximum_profit = 0;
    for (int i = 0; i < prices.size(); i++) {
      for (int j = i + 1; j < prices.size(); j++) {
        maximum_profit = max(maximum_profit, prices[j] - prices[i]);
      }
    }

    return maximum_profit;
  }
};
