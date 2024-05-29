class KthLargest {
public:
    int kth_number;
    vector<int> numbers;
    KthLargest(int k, vector<int>& nums) {
        kth_number = k;
        numbers = nums;
        sort(numbers.begin(), numbers.end());
    }
    
    int add(int val) {
        auto i = numbers.begin();
        while (i != numbers.end()) {
            if (val < *i) {
                break;
            }
            i++;
        }
        numbers.insert(i, val);

        return numbers[numbers.size() - kth_number];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
