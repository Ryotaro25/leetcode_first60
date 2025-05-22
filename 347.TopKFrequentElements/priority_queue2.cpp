class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    if (nums.empty()) {
      return {};
    }

    map<int, int> num_to_frequency;
    for (auto num : nums) {
      num_to_frequency[num]++;
    }

    priority_queue<pair<int, int>> descending_nums;
    for (auto [num, freq] : num_to_frequency) {
      descending_nums.push({freq, num});
    }

    vector<int> top_k_frequent_nums;
    for (int i = 0; i < k; i++) {
      top_k_frequent_nums.push_back(descending_nums.top().second);
      descending_nums.pop();
    }
    return top_k_frequent_nums;
  }
};
