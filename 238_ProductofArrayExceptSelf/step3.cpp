class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& nums) {
      if (nums.size() == 0) {
        return {};
      }

      vector<int> products_except_self(nums.size(), 1);
      int prefix_product = 1;
      for (int i = 0; i < nums.size(); i++) {
        products_except_self[i] *= prefix_product;
        prefix_product *= nums[i];
      }

      int suffix_product = 1;
      for (int i = nums.size() - 1; i >= 0; i--) {
        products_except_self[i] *= suffix_product;
        suffix_product *= nums[i];
      }

      return products_except_self;
    }
  };
