#include "step4.h"  // ヘッダーファイルをインクルード

int Solution::coinChange(vector<int>& coins, int target_amount) {
  vector<int> min_coins(target_amount + 1, UNREACHABLE);

  min_coins[0] = 0;
  for (int amount = 1; amount <= target_amount; amount++) {
    for (int coin_val : coins) {
      int remain = amount - coin_val;
      if (remain < 0) {
        continue;
      }

      if (min_coins[remain] == UNREACHABLE) {
        continue;
      }

      min_coins[amount] = min(min_coins[amount], min_coins[remain] + 1);
    }
  }
  if (min_coins.back() != UNREACHABLE) {
    return min_coins.back();
  }
  return UNACHIVABLE;
}

int main() {
  // ソルーションオブジェクトの作成
  Solution solution;
  return 0; // 終了ステータスを返す
}
