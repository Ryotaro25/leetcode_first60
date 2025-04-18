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
        auto position = lower_bound(numbers.begin(), numbers.end(), val);
        numbers.insert(position, val);

        return numbers[numbers.size() - kth_number];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */