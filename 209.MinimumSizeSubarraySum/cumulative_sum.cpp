class Solution {
  public:
    int minSubArrayLen(int target, vector<int>& nums) {
      vector<int> cumulative_sum(nums.size() + 1);
      cumulative_sum[0] = 0;
      for (int i = 0; i < nums.size(); i++) {
        cumulative_sum[i + 1] = cumulative_sum[i] + nums[i];
      }

      int min_length = NOANSWER;
      int left = 0;
      int right = 1;
      while (right < cumulative_sum.size()) {
        while (left < right) {
          if (cumulative_sum[right] - cumulative_sum[left] < target) {
            break;
          }
          min_length = min(min_length, right - left);
          left++;
        }
        right++;
      }

      if (min_length == NOANSWER) {
        return 0;
      }
      return min_length;
    }

  private:
    static constexpr int NOANSWER = numeric_limits<int>::max();
  };