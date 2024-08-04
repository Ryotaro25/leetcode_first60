class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> nums_counts;
        for (auto num : nums) {
            nums_counts[num]++;
        }
 
        vector<pair<int, int>> descending_numbers;
        for (auto num : nums_counts) {
            descending_numbers.push_back({num.second, num.first});
        }
        sort(descending_numbers.rbegin(), descending_numbers.rend());

        vector<int> topk_numbers;
        for (int i = 0; i < k; i++) {
            topk_numbers.push_back(descending_numbers[i].second);
        }
        return topk_numbers;
    }
};
