class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> cumulative_sum(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            cumulative_sum[i + 1] = cumulative_sum[i] + nums[i];
        }

        int count = 0;
        for (int left = 0; left < nums.size(); left++) {
            for (int right = left + 1; right <= nums.size(); right++) {
                if (cumulative_sum[right] - cumulative_sum[left] == k) {
                    count++;
                }
            }
        }

        return count;
    }
};
