class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        vector<int> two_indices;
        for (int i = 0; i < numbers.size(); i++) {
            for (int j = 0; j < numbers.size(); j++) {
                if (i != j && target - numbers[i] - numbers[j] == 0) {
                    two_indices.push_back(i);
                    two_indices.push_back(j);
                    return two_indices;
                }
            }
        }
        return two_indices;
    }
};
