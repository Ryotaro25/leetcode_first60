class KthLargest {
public:
  KthLargest(int k, vector<int>& nums) {
    size = k;
    for (auto num : nums) {
      add(num);
    }
  }

  int add(int val) {
    kth_largest_values.push(val);
    if (kth_largest_values.size() > size) {
      kth_largest_values.pop();
    }
    return kth_largest_values.top();
  }

private:
  int size;
  priority_queue<int, vector<int>, greater<int>> kth_largest_values;

};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
