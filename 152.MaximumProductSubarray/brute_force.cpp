class Solution {
public:
    int maxProduct(vector<int>& nums) {
      if (nums.empty()) {
        return 0;
      }
      int max_product = numeric_limits<int>::min();
      for (int i = 0; i < nums.size(); i++) {
        int temp = 1;
        for (int j = i; j < nums.size(); j++) {
          temp *= nums[j];
          max_product = max(max_product, temp);
        }
      }
      return max_product;
    }
};
