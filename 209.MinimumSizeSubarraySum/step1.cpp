class Solution {
  public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int min_length = NOANSWER;
      int sum = 0;
  
      int left = 0;
      for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];
        while (sum >= target) {
          min_length = min(min_length, right - left + 1);
          sum -= nums[left];
          left++;
        }
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
  