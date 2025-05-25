class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sum_to_count;
        int sum = 0;
        int count = 0;

        for (auto& num : nums) {
            sum_to_count[sum]++;
            sum += num;
            int target_num = sum - k;
            if (sum_to_count.contains(target_num)) {
                count += sum_to_count[target_num];
            }
        }

        return count;
    }
};
