class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& nums) {
      if (nums.empty()) {
        return {};
      }

      int num_size = nums.size();

      vector<int> prefix_products(num_size, 1);
      partial_sum(nums.begin(), nums.end() - 1, prefix_products.begin() + 1, multiplies<int>());

      vector<int> suffix_products(num_size, 1);
      partial_sum(nums.rbegin(), nums.rend() - 1, suffix_products.rbegin() + 1, multiplies<int>());

      vector<int> products_except_self(num_size);
      transform(prefix_products.begin(), prefix_products.end(), suffix_products.begin(),
                products_except_self.begin(), multiplies<int>());
      return products_except_self;
    }
  };
