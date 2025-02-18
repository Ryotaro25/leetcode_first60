class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    }
    vector<int> partial_sums(nums.size() + 1, 0);
 
    for (int i = 0; i < nums.size(); i++) {
      partial_sums[i + 1] = partial_sums[i] + nums[i];
    }

    // 累積和を計算
    // 左の累積和の最小値を計算する。
    // 最大を取る。
    int min_sum = numeric_limits<int>::max();
    int max_sum = numeric_limits<int>::min(); 
    for (int i = 0; i < partial_sums.size(); i++) {
      int sum = partial_sums[i] - min_sum;
      max_sum = max(max_sum, sum);
      min_sum = min(min_sum, partial_sums[i]);
    }

    return max_sum;
  }
};
