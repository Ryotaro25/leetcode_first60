class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> numbers_to_index;
        for (int i = 0; i < numbers.size(); i++) {
            int remaining = target - numbers[i];
            if (numbers_to_index.contains(remaining)) {
                return {numbers_to_index[remaining], i};
            }
            numbers_to_index[numbers[i]] = i;
        }
        return {};
    }
};