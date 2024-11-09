// min_heapの実装方法https://www.geeksforgeeks.org/implement-min-heap-using-stl/
// 比較方法の部分はわからなかったのでchatGptを使用
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_to_frequency;
        for (auto num : nums) {
            num_to_frequency[num]++;
        }

        auto compare = [](pair<int, int>& a, pair<int, int>& b) {
            return a.first > b.first;  // 頻度が小さいものが優先される
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> min_heap(compare);

        for (auto& [num, count] : num_to_frequency) {
            min_heap.push({count, num});
            // 小さいものからなくなる
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }

        vector<int> top_k_numbers;
        while (!min_heap.empty()) {
            top_k_numbers.push_back(min_heap.top().second);
            min_heap.pop();
        }

        return top_k_numbers;
    }
};
