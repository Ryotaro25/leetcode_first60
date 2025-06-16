class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    vector<int> increasing_nums;
    increasing_nums.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] > increasing_nums.back()) {
        increasing_nums.push_back(nums[i]);
        continue;
      }
      // find first larger or equal num
      int index = FindFirstLargerOrEqualIndex(increasing_nums, nums[i]);
      increasing_nums[index] = nums[i];
    }

    return increasing_nums.size();
  }

private:
  int FindFirstLargerOrEqualIndex(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();

    while (left < right) {
      int middle = left + (right - left) / 2;
      if (nums[middle] < target) {
        // middle の値がターゲットより小さい場合、
        // ターゲットは middle の右側にある可能性がある。
        // したがって、探索範囲を [middle + 1, right) に絞る
        left = middle + 1;
      } else {
        // middle の値がターゲット以上の場合、
        // middle は答えの候補であるか、ターゲットは middle の左側にある可能性がある。
        // したがって、探索範囲を [left, middle) に絞る。
        right = middle;
      }
    }
    return left;
  }
};
