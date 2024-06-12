class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> num_to_index;
        for (int i = 0; i < numbers.size(); i++) {
            int remaining = target - numbers[i];
            if (num_to_index.contains(remaining)) {
                return {num_to_index[remaining], i};
            }
            num_to_index[numbers[i]] = i;
        }
        return {};
    }
};