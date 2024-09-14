// bucket sort
// 参考https://leetcode.com/problems/top-k-frequent-elements/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>num_to_frequency;
        for(auto num : nums){
            num_to_frequency[num]++;
        }

        int max_frequency = 0;
        for (auto [num, count] : num_to_frequency) {
            max_frequency = max(max_frequency, count);
        }

        vector<vector<int>> bucket(max_frequency + 1);
        for(auto [num, count] : num_to_frequency){
            bucket[count].push_back(num);
        }

        vector<int>top_k_numbers;
        for (int i = max_frequency; i >= 0 && top_k_numbers.size() < k; i--) {
            for (auto num : bucket[i]) {
                top_k_numbers.push_back(num);
                if (top_k_numbers.size() == k) {
                    break;
                }
            }
        }

        return top_k_numbers;
    }
};
