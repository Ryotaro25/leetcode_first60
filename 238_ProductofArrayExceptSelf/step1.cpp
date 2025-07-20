class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& nums) {
      if (nums.size() == 0) {
        return {};
      }
      vector<int> prefix_products(nums.size());
      // デフォルトの初期化は0だが、
      // indexが0の場所の計算に影響を与えないように1で初期化する
      prefix_products[0] = 1;
      for (int i = 1; i < nums.size(); i++) {
        prefix_products[i] = prefix_products[i - 1] * nums[i - 1];
      }

      vector<int> suffix_products(nums.size());
      suffix_products[nums.size() - 1] = 1;
      for (int i = nums.size() - 2; i >= 0; i--) {
        suffix_products[i] = suffix_products[i + 1] * nums[i + 1];
      }

      vector<int> products_except_self(nums.size());
      for (int i = 0; i < nums.size(); i++) {
        products_except_self[i] = prefix_products[i] * suffix_products[i];
      }
      return products_except_self;
    }
  };
