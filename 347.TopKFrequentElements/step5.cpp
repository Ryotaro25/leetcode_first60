// priority_queue.cppの修正版
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>num_to_freqency;
        for(auto num : nums){
            num_to_freqency[num]++;
        }

        priority_queue<pair<int,int>>max_heap_numbers;
        for(auto [num, count] : num_to_freqency){
            max_heap_numbers.push({count, num});
        }

        vector<int>top_k_numbers;
        for (int i = 0; i < k; i++) {
            int element = max_heap_numbers.top().second;
            top_k_numbers.push_back(element);
            max_heap_numbers.pop();
        }

        return top_k_numbers;
    }
};
