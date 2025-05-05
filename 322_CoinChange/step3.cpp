class Solution {
public:
  int coinChange(vector<int>& coins, int target_amount) {
    vector<int> num_min_coins(target_amount + 1, UNDEFINED);

    num_min_coins[0] = 0;
    for (int amount = 1; amount <= target_amount; amount++) {
      for (const auto& coin_val : coins) {
        int remain = amount - coin_val;
        if (remain < 0) {
          continue;
        }

        if (num_min_coins[remain] == UNDEFINED) {
          continue;
        }

        num_min_coins[amount] = min(num_min_coins[amount], num_min_coins[remain] + 1);
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
