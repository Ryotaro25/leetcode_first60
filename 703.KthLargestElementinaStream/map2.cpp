class KthLargest {
public:
  KthLargest(int k, vector<int>& nums) {
    size = k;
    for (auto num : nums) {
      add(num);
    }
  }

  int add(int val) {
    values_to_count[val]++;

    int count = 0;
    for (auto it = values_to_count.rbegin(); it != values_to_count.rend(); it++) {
      count += it->second;
      if (count >= size) {
        return it->first;
      }
    }

    return -1;
  }

private:
  int size;
  map<int, int> values_to_count;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */