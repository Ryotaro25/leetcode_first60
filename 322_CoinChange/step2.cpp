class Solution {
public:
  int coinChange(vector<int>& coins, int target_amount) {
    vector<int> num_min_coins(target_amount + 1, UNDEFINED);
    // amount 0に必要なコインは0枚
    num_min_coins[0] = 0;
    for (int amount = 1; amount <= target_amount; amount++) {
      for (const auto& coin_val : coins) {
        int remain_amount = amount - coin_val;
        if (remain_amount < 0) {
          continue;
        }

        if (num_min_coins[remain_amount] == UNDEFINED) {
          continue;
        }

        // amount iに必要な最小のコイン数を格納
        num_min_coins[amount] = min(num_min_coins[amount], num_min_coins[remain_amount] + 1);
      }
      
    }
    if (num_min_coins.back() != UNDEFINED) {
      return num_min_coins.back();
    }
    return -1;
  }

private:
  static constexpr int UNDEFINED = std::numeric_limits<int>::max();
};
