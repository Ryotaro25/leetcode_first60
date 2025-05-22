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

    vector<FrequencyAndNum> frequency_to_nums;
    for (auto [num, freq] : num_to_frequency) {
      frequency_to_nums.push_back({freq, num});
    }
    sort(frequency_to_nums.rbegin(), frequency_to_nums.rend());

    vector<int> top_k_frequent_nums;
    for (int i = 0; i < k; i++) {
      top_k_frequent_nums.push_back(frequency_to_nums[i].num);
    }
    return top_k_frequent_nums;
  }

private:
  struct FrequencyAndNum {
    int frequency;
    int num;

    bool operator<(const FrequencyAndNum& other) {
      return frequency < other.frequency;
    }
  };
};
