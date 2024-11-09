class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> nums_to_frequency;
    for (auto num : nums) {
      nums_to_frequency[num]++;
    }

    // pairやtuppleは避けたいがsortを使いたいのでpairを用いる
    vector<pair<int, int>> descending_frequency;
    for (auto [val, frequency] : nums_to_frequency) {
      descending_frequency.push_back({frequency, val});
    }
    sort(descending_frequency.rbegin(), descending_frequency.rend());

    vector<int> k_elements;
    for (int i = 0; i < k; i++) {
      k_elements.push_back(descending_frequency[i].second);
    }

    return k_elements;
  }
};
