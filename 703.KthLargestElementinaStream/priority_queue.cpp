class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>>largest_numbers;
    int kth_number;
    KthLargest(int k, vector<int>& nums) {
        kth_number = k;
        for (int i : nums) {
            add(i);
        }
    }
    
    int add(int val) {
        if (kth_number > largest_numbers.size()) {
            largest_numbers.push(val);
        } else {
            if (val > largest_numbers.top()) {
                largest_numbers.pop();
                largest_numbers.push(val);
            }
        }
        return largest_numbers.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
