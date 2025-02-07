class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> min_amounts(amount + 1, UNDEFINED);
    // amount 0に必要なコインは0枚
    min_amounts[0] = 0;
    for (int i = 1; i <= amount; i++) {
      for (auto coin : coins) {
        if (i < coin) {
          continue;
        }

        int remain_amount = i - coin;
        if (min_amounts[remain_amount] == UNDEFINED) {
          continue;
        }

        // amount iに必要な最小のコイン数を格納
        min_amounts[i] = min(min_amounts[i], min_amounts[remain_amount] + 1);
      }
      
    }

    if (min_amounts.back() != UNDEFINED) {
      return min_amounts.back();
    }
    return -1;
  }

private:
  static constexpr int UNDEFINED = std::numeric_limits<int>::max();
};
