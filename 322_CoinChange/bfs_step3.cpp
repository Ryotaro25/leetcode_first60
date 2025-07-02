class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    if (coins.empty()) {
      return -1;
    }

    int fewest_num_coins = UNDEFINED;
    vector<int> min_coins_for_amount(amount + 1, std::numeric_limits<int>::max());
    // initial state
    min_coins_for_amount[amount] = 0;

    queue<TargetAndNumCoins> target_and_num_coins;
    target_and_num_coins.push({amount, 0});

    while (!target_and_num_coins.empty()) {
      auto [target, num_coins] = target_and_num_coins.front();
      target_and_num_coins.pop();
      if (target == 0) {
        if (fewest_num_coins == UNDEFINED) {
          fewest_num_coins = num_coins;
          continue;
        }
        fewest_num_coins = min(fewest_num_coins, num_coins);
      }

      for (int coin_val : coins) {
        int next_target = target - coin_val;
        // amount can not be negative
        if (next_target < 0) {
          continue;
        }
        int next_num_coins = num_coins + 1;
        // there's already min coins patterns
        if (next_num_coins >= min_coins_for_amount[next_target]) {
          continue;
        }
        min_coins_for_amount[next_target] = next_num_coins;
        target_and_num_coins.push({next_target, next_num_coins});
      }
    }
    return fewest_num_coins;
  }

private:
  static constexpr int UNDEFINED = -1;
  struct TargetAndNumCoins {
    int target_amount;
    int num_coins;
  };
};
