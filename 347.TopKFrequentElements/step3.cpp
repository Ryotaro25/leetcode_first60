class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> nums_frequency;
        for (auto num : nums) {
            nums_frequency[num]++;
        }

        vector<pair<int, int>> descending_frequency;
        for (auto num : nums_frequency) {
            int element = num.first;
            int count = num.second;
            descending_frequency.push_back({count, element});
        }
        sort(descending_frequency.rbegin(), descending_frequency.rend());

        vector<int> topk_numbers;
        for (int i = 0; i < k; i++) {
            int element = descending_frequency[i].second;
            topk_numbers.push_back(element);
        }

        return topk_numbers;
    }
};

