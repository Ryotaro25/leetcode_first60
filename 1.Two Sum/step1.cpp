class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> numbers_and_index;
        vector<int> two_indices;
        for (int i = 0; i < nums.size(); i++) {
            int remaining = target - nums[i];
            if (numbers_and_index.contains(remaining)) {
                return {numbers_and_index[remaining], i};
            }
            numbers_and_index.insert({nums[i], i});
        }

        return two_indices;
    }
};
