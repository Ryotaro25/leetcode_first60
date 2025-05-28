class Solution {
    private:
        // vectorを分割して基準以上と以下に配置
        int partition(vector<pair<int, int>>& counts, int left, int right, int pivot_index) {
            //intの登場回数を分割の基準とする
            int pivot_frequency = counts[pivot_index].second;
            swap(counts[pivot_index], counts[right]);
            int sorted_i = left;
            for (int i = left; i < right; ++i) {
                if (counts[i].second < pivot_frequency) {
                    swap(counts[i], counts[sorted_i]);
                    sorted_i++;
                }
            }
            swap(counts[right], counts[sorted_i]);
            return sorted_i;
        }

        void quickselect(vector<pair<int, int>>& counts, int left, int right, int kth_smallest) {
            //再帰を使わないでループで動かす
            while (left < right) {
                // 特定のパターンに依存させない
                int pivot_index = left + rand() % (right - left + 1);
                pivot_index = partition(counts, left, right, pivot_index);
                // kまででストップする
                if (kth_smallest == pivot_index) {
                    return;
                } else if (kth_smallest < pivot_index) {
                    right = pivot_index - 1;
                } else {
                    left = pivot_index + 1;
                }
            }
        }

        vector<pair<int, int>> count_frequency(vector<int>& nums) {
            map<int, int> frequency_numbers;
            for (int num : nums) {
                frequency_numbers[num]++;
            }

            vector<pair<int, int>> v(frequency_numbers.begin(), frequency_numbers.end());
            return v;
        }

    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            vector<pair<int, int>> nums_to_frequency = count_frequency(nums);
        
            int number_count = nums_to_frequency.size();
            quickselect(nums_to_frequency, 0, number_count - 1, number_count - k);
        
            vector<int> top_k_numbers;
            for (int i = number_count - k; i < number_count; ++i) {
                int element = nums_to_frequency[i].first;
                top_k_numbers.push_back(element);
            }
            return top_k_numbers;
        }
};
