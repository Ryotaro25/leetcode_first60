class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> visited(amount + 1, UNDEFINED);
    return CoinChange(coins, visited, amount);
  }

private:
  static constexpr int UNDEFINED = std::numeric_limits<int>::max();
  int CoinChange(const vector<int>& coins, vector<int>& visited, int amount) {
    if (amount < 0) {
      return -1;
    }
    if (amount == 0) {
      return 0;
    }
    if (visited[amount] != UNDEFINED) {
      return visited[amount];
    }

    int min_num_coin = UNDEFINED;
    for (int coin_val : coins) {
      int num_coin = CoinChange(coins, visited, amount - coin_val);
      if (num_coin >= 0 && num_coin < min_num_coin) {
        min_num_coin = num_coin + 1;
      }
    }
    if (min_num_coin == UNDEFINED) {
      min_num_coin = -1;
    }
    visited[amount] = min_num_coin;
    return visited[amount];
  }
};
