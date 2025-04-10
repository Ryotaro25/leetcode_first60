#ifndef CoinChange_MAIN_STEP4_H_ // The format of the symbol name should be <PROJECT>_<PATH>_<FILE>_H_.
#define CoinChange_MAIN_STEP4_H_

#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
  int coinChange(vector<int>& coins, int target_amount);

private:
  static constexpr int UNREACHABLE = std::numeric_limits<int>::max();
  static constexpr int UNACHIVABLE = -1;
};

#endif // CoinChange_MAIN_STEP4_H_
