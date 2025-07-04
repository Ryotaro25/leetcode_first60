class Solution {
  public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int min_length = NOANSWER;
      int sum = 0;
  
      int right = 0;
      for (int left = 0; left < nums.size(); left++) {
        while (right < nums.size() && sum < target) {
          sum += nums[right];
          right++;
        }
        if (sum < target) {
          break;
        }
        min_length = min(min_length, right - left);
        sum -= nums[left];
      }

      if (min_length != NOANSWER) {
        return min_length;
      } else {
        return 0;
      }
    }
  
  private:
    static constexpr int NOANSWER = numeric_limits<int>::max();
  };
  