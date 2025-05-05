class Solution {
public:
  int coinChange(vector<int>& coins, int target_amount) {
    vector<bool> visited(target_amount + 1, false);

    queue<NumCoinsAndAmount> num_coins_and_amount;
    num_coins_and_amount.push({0, 0});
    visited[0] = true;

    while (!num_coins_and_amount.empty()) {
      auto [num_coins, amount] = num_coins_and_amount.front();
      num_coins_and_amount.pop();

      if (amount == target_amount) {
        return num_coins;
      }

      // ここにvisited[amount] = true;をおくとMemory Limit Exceeded
      // 各コインを探索した後でvisitedが更新されるので

      for (const auto& coin_val : coins) {
        if (amount > target_amount - coin_val) {
          continue;
        }

        int next_amount = amount + coin_val; // ここでintのrangeを超える場合がある
        if (visited[next_amount]) {
          continue;
        }
        visited[next_amount] = true;
        num_coins_and_amount.push({num_coins + 1, next_amount});
      }
    }

    return -1;
  }

private:
  struct NumCoinsAndAmount {
    int num_coins;
    int amount;
  };
};
