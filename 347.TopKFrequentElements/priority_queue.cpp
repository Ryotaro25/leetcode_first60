class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>nums_frequency;
        for(auto num : nums){
            nums_frequency[num]++;
        }

        priority_queue<pair<int,int>>descending_numbers;
        for(auto num : nums_frequency){
            int element = num.first;
            int count = num.second;
            descending_numbers.push({count,element});
        }

        vector<int>top_k_numbers;
        for (int i = 0; i < k; i++) {
            int element = descending_numbers.top().second;
            top_k_numbers.push_back(element);
            descending_numbers.pop();
        }

        return top_k_numbers;
    }
};
